#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    string ans;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) ans = ans + '1';
    else{
        ans = ans + "0000";
        cout << ans;
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]){
        if(s1[2] - 'A' <= 2){
            if(s2[2] - 'A' <= 2) ans = ans + "11";
            else ans = ans + "10";
        }
        else{
            if(s2[2] - 'A' > 2) ans = ans + "11";
            else ans = ans + "10";
        }
    }
    else ans = ans + "00";
    if(ans[2] == '1' && abs((s1[2] - 'A') - (s2[2] - 'A')) == 1) ans = ans + '1';
    else ans = ans + '0';
    cout << ans;
}
