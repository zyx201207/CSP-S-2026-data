#include <bits/stdc++.h>
using namespace std;
string c_1,c_2,s_1,s_2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c_1 >> s_1 >> c_2 >> s_2;
    if(c_1 != c_2) cout << "0000";
    else if(c_1 == c_2){
        if(s_1[0] != s_2[0] || s_1[1] != s_2[1]){
            cout << "1000";
        }
        else{
            if((s_1[2] == 'D' && s_2[2] == 'F') || (s_2[2] == 'D' && s_1[2] == 'F'))cout << "1111";
            else if((s_1[2] - 'A') <= 2 && (s_2[2] - 'A') <= 2){
                if((s_1[2] - 'A') - (s_2[2] - 'A') == 1 || (s_1[2] - 'A') - (s_2[2] - 'A') == -1){
                    cout << "1111";
                }
                else{
                    cout << "1110";
                }
            }
            else{
                cout << "1100";
            }
        }
    }
    return 0;
}
