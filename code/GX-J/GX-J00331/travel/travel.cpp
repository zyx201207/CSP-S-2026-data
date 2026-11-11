#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    if (a1==a2){
        cout<<"1";
        if (b1[0]==b2[0]&&b1[1]==b2[1]){
            cout<<"1";
            int f1,f2;
            if (b1[2]=='A'||b1[12]=='B'||b1[2]=='C'){
                f1=1;
            }else{
                f1=0;
            }
            if (b2[2]=='D'||b2[2]=='F'){
                f2=0;
            }else{
                f2=1;
            }
            if (f2==f1){
                cout<<"1";
                if (b2[2]+1==b1[2]||b2[2]-1==b1[2]){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
