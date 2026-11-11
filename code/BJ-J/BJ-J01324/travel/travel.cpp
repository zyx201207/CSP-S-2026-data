#include <bits/stdc++.h>
using namespace std;
long long c1, c2;
string s1, s2, ans;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1;
    cin >> c2 >> s2;
    if(c1 == c2){
        ans += '1';
    }else ans += '0';
    if(ans[0] == '1' && s1[0] == s2[0] && s1[1] == s2[1]){
        ans += '1';
    }else{
        ans += '0';
    }
    if(ans[1] == '1' && ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))){
        ans += '1';
    }else{
        ans += '0';
    }
    if(ans[2] == '1' && abs(s1[2] - s2[2]) == 1 && max(s1[2], s2[2]) != 'D'){
        ans += '1';
    }else{
        ans += '0';
    }
    cout << ans;
    return 0;
}
