#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    string a2,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<1;
        if(a2[0]*10+a2[1]*10==b2[0]*10+b2[1]){
            cout<<1;
            if((a2[2]<='C'&&b2[2]<='C'&&a2[2]!=b2[2])||(a[2]>'C'&&b[2]>'C'&&a2[2]!=b2[2])){
                cout<<1;
                if(a2[2]-b2[2]==-1||a2[2]-b2[2]==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<00;
            }
        }else{
            cout<<000;
        }
    }else{
        cout<<0000;
    }
    return 0;
}