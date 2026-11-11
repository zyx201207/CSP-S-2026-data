#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s1, s2, s3, s4, ans(4, '0');
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1 == s3){  // same flat
        ans[0] = '1';
        if(s2.substr(0, 2) == s4.substr(0, 2)){ // same line
            ans[1] = '1';
            if((s2[2] <= 'C' && s4[2] <= 'C') || (s2[2] > 'C' && s4[2] > 'C')){ //same side
                ans[2] = '1';
                if(s2[2] + 1 == s4[2] || s4[2] + 1 == s2[2]){
                    ans[3] = '1';
                }
            }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
