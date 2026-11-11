#include<bits/stdc++.h>
using namespace std;
string a[5],b[5];
int v,v1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a[1]>>b[1]>>a[2]>>b[2];
    if(a[1]==a[2]){
        cout<<1;
        v1=1;
    }
    else{
        cout<<0;
    }
    if(b[1][0]+b[1][1]==b[2][0]+b[2][1]&&v1){
        cout<<1;
        v1=2;
    }
    else{
        cout<<0;
        v1=0;
    }
    if(((b[1][2]<='C'&&b[2][2]<='C')||(b[1][2]>='D'&&b[2][2]>='D'))&&v1==2){
        cout<<1;
        if(b[1][2]<='C'){
            v=1;
        }
        else{
            v=2;
        }
    }
    else{
        cout<<0;
    }
    if(v){
        if(v==1){
            if(b[1][2]+1==b[2][2]){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else{
            if(b[1][2]+2==b[2][2]){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
