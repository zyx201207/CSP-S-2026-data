#include <bits/stdc++.h>
using namespace std;
int a1,b1,a3,b3;
string a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    a3=a2[2]-'A';
    b3=b2[2]-'A';
    a2=a2.substr(0,2);
    b2=b2.substr(0,2);
    //cout<<a1<<a2<<a3<<endl<<b1<<b2<<b3;
    if(a1==b1){
        cout<<"1";
        if(a2==b2){
            cout<<"1";
            if((a3<=2&&b3<=2)||(a3>=3&&b3>=3)){
                cout<<"1";
                if(a3-b3==1||a3-b3==-1){
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
    }
    return 0;
}
