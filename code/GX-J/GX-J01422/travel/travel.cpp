#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c_1, s_1, c_2, s_2;
    cin >> c_1 >> c_2 >> s_1 >> s_2;
    string ans ="";
    if(c_1 == s_1){
        ans += '1';

        if(c_2[0] == s_2[0] && c_2[1] == s_2[1]){
                ans += '1';
            if(c_2[2] <= 'C'){
                if(c_2[2]<='C' && s_2[2]<='C'){
                    ans += '1';
                    if(abs(c_2[2] - s_2[2]) == 1){
                        ans += '1';
                    }else{
                        ans += '0';

                    }
                }else{
                    ans += "00";
                }
            }else{
                if(c_2[2]=='D' && s_2[2]=='E' || c_2[2]=='E' && s_2[2]=='D'){
                    ans += "11";
                }else{
                    ans += "00";
                }
            }
            }else{
                ans += "000";
            }

    }else{
        ans = "0000";
    }
    cout << ans;
    return 0;
}
