class Solution {
    public:
        Solution () : numericMap({{2, {'a','b','c'}}, {3, {'d','e','f'}}, {4, {'g','h','i'}}, {5, {'j','k','l'}}, {6, {'m','n','o'}},
        {7, {'p','q','r','s'}}, {8, {'t','u','v'}}, {9, {'w','x','y','z'}}}) { }
        vector<string> letterCombinations(string digits) {
            if (digits.size() == 0) {
                return {};
            }
            return expand(digits);
        }
    private:
        const unordered_map<int, vector<char>> numericMap;

        vector<string> expand(string digits) {
            if (digits.size() == 0) {
                cout << "here";
                return {""};
            }
            auto prev = expand(digits.substr(1, digits.size() - 1));
            auto num = digits[0] - '0';
            vector<string> strs;
            for (auto& ch:numericMap.at(num)) {
                for (auto& prevList:prev) {
                    strs.push_back(ch + prevList);
                }            
            }
            return strs;
        }
};
