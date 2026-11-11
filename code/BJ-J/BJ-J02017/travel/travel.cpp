#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << "1";
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << "1";
            if(abs((s1[2] - 'A' + 1) - (s2[2] - 'A' + 1)) <= 2){
                if((s1[2] == 'C' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'B') ||(s1[2] == 'D' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'D')){
                    cout << "00";
                }
                else {
                    cout << "1";
                    if(abs((s1[2] - 'A' + 1) - (s2[2] - 'A' + 1)) == 1){
                        cout << "1";
                    }
                    else {
                        cout << "0";
                    }
                }
            }
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}