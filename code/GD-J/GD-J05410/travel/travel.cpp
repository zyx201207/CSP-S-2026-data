#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2, ans = "";
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2) {
        ans += '1';
        if(s1[0] == s2[0] && s1[1] == s2[1]) {
            ans += '1';
            if( (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') ) {
                ans += '1';
                if(s1[2] == s2[2] + 1 || s2[2] == s1[2] + 1) ans += '1';
            }
        }
    }
    int n = 4 - ans.length();
    while(n--) ans += '0';

    cout << ans << endl;
    return 0;
}
