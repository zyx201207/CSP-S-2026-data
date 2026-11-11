#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2, ans;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    ans += (c1 == c2) + '0';
    ans += (ans[0] - '0') * (s1[0] == s2[0] && s1[1] == s2[1]) + '0';
    ans += (ans[1] - '0') * ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) + '0';
    ans += (ans[2] - '0') * (abs(s1[2] - s2[2]) == 1) + '0';
    cout << ans;
    return 0;
}
