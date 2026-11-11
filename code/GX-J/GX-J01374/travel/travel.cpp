#include<bits/stdc++.h>
using namespace std;
string x1,x2,z1,z2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x1>>z1>>x2>>z2;
    if(x1==x2){
        cout<<"1";
        if(z1[0]==z2[0] and z1[1]==z2[1]){
            cout<<"1";
            if((z1[2]>='A' and z1[2]<='C' and z2[2]>='A' and z2[2]<='C')or(z1[2]>='D' and z1[2]<='F' and z2[2]>='D' and z2[2]<='F')){
                cout<<"1";
                if(z1[2]+1==z2[2] or z1[2]-1==z2[2]){
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
