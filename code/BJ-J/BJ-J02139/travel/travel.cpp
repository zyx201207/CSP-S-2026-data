#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << "1";
        if((string){s1[0]}+(string){s1[1]}==(string){s2[0]}+(string){s2[1]}){
            cout << "1";
            if(((string){s1[2]}<="C"&&(string){s2[2]}<="C")||((string){s1[2]}>"C"&&(string){s2[2]}>"C")){
                cout << "1";
                if(abs(s1[2]-s2[2])==1){
                    cout << "1";
                }
                else{
                    cout << "0";
                }
            }
            else{
                cout << "00";
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
