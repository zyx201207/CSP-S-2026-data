#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s = "";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a;
        char c;
        cin >> a >> c;
        for (long long j = 0; j < a; j++) s += c;
    }
    string s_left = s.substr(0, s.size() / 2), s_right = s.substr(s.size() / 2 + 1, s.size() - 1);
    reverse(s_left.begin(), s_left.end());
    long long difference = 0;
    for (long long i = 0; i < s_left.size(); i++) {
        if (s_left[i] != s_right[i]) difference++;
    }
    cout << difference;
    return 0;
}
