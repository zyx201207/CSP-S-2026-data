#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string sa1,sa2,sc1,sc2;
    cin >> sa1 >> sa2 >> sc1 >> sc2;
    if(sa1==sc1){
        cout << "1";
        if(sa2[0]==sc2[0] && sa2[1]==sc2[1]){
            cout << "1";
            if(sa2[2]-'A'<=2 && sc2[2]-'A'<=2 || ((sa2[2]=='D' && sc2[2]=='F') || (sa2[2]=='F' && sc2[2]=='D'))){
                cout << "1";
                if(((sa2[2]=='D' && sc2[2]=='F') || (sa2[2]=='F' && sc2[2]=='D')) || abs((sa2[2]-'A')-(sc2[2]-'A'))==1){
                    cout << "1";
                }else cout << "0";
            }else cout << "00";
        }else cout << "000";
    }else cout << "0000";
    return 0;
}
