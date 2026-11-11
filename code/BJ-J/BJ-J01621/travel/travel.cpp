#include <bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout <<1;
        if(s1.substr(0,2) == s2.substr(0,2)){
            cout << 1;
            char S1 = s1[2],S2 = s2[2];
            if(S1 >= 'A' && S1 <= 'C' && S2 >= 'A' && S2 <= 'C' || S1 >= 'D' && S1 <= 'F' && S2 >= 'D' && S2 <= 'F'){
                cout << 1;
                if(S1 >= 'A' && S1 <= 'C' && S2 >= 'A' && S2 <= 'C'){
                    if(abs(S1-S2) == 1){
                        cout << 1;
                    }
                    else{
                        cout << 0;
                    }
                }
                else{
                    cout << 1;
                }
            }
            else{
                cout <<"00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
