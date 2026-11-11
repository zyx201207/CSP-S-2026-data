#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string ca, cb, sa, sb;
    string ans = "0000";
    cin >> ca >> sa >> cb >> sb;
    int cnt = 0;
    if (ca == cb){
        ans[0] = '1';
        if (sa[0] == sb[0] && sa[1] == sb[1]){
            ans[1] = '1';
            if (sa[2] >= 'A' && sa[2] <= 'C' && sb[2] >= 'A' && sb[2] <= 'C'){
                ans[2] = '1';
                if (sa[2] == sb[2] + 1 || sa[2] == sb[2] - 1){
                    ans[3] = '1';
                }
            }
            else if (sa[2] == 'D' && sb[2] == 'F'){
                ans[2] = '1';
                ans[3] = '1';
            }
            else if (sa[2] == 'F' && sb[2] == 'D'){
                ans[2] = '1';
                ans[3] = '1';
            }
        }
    }
    cout << ans << '\n';
    return 0;
}