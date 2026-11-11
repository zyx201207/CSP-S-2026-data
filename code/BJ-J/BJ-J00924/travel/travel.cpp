#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    bool fl1=1,fl2=1,fl3=1,fl4=0;
    for(int i=0;i<2;i++)if(a1[i]!=a2[i])fl1=0;
    for(int i=0;i<2;i++)if(b1[i]!=b2[i])fl2=0;
    if(a2[2]>='D' && b2[2]<='C' || b2[2]<='C' && a2[2]>='D')fl3=0;
    if(abs(int(a2[2])-int(b2[2]))==1)fl4=1;
    if(fl1==1){
        cout<<"1";
        if(fl2==1){
            cout<<"1";
            if(fl3==1){
                cout<<"1";
                if(fl4==1)cout<<"1";
                else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}