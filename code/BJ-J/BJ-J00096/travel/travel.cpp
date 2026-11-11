#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2;
bool ans[10];
int main() {
    freopen("travel.in","r",stdin)
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    ans[1] = (c1 == c2);
    ans[2] = (s1[0] == s2[0] && s1[1] == s2[1] && ans[1]);
    if (65 <= s1[2] && s1[2] <= 67 && 65 <= s2[2] && s2[2] <= 67) {
        ans[3] = true;
        if (s1[2] == 66 || s2[2] == 66) ans[4] = true;
        if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) ans[4] = true;
    }
    if (68 <= s1[2] <= 70 && 68 <= s2[2] <= 70 && ans[1] && ans[2]) {
        ans[3] = true;
    }
    if (s1[2] == 66 || s2[2] == 66 || s1[2] == 68 || s1[2] == 70 && ans[1] && ans[2]) {
        ans[3] = true;
        if (ans[3]) ans[4] = true;
    }
    for (int i = 0;i < 4;i++) {
        if (ans[i] == true) cout << "1";
        else cout << "0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}