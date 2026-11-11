#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int tp1,tp2;
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1) cout<<1;
    else{cout<<"0000";return 0;}
    if(a2[0]==b2[0]&&a2[1]==b2[1]) cout<<1;
    else{cout<<"000";return 0;}
    if(a2[2]<'D') tp1=0;
    else tp1=1;
    if(b2[2]<'D') tp2=0;
    else tp2=1;
    if(tp1==tp2){
        cout<<1;
        if(tp1) cout<<1;
        else if(abs(a2[2]-b2[2])==1) cout<<1;
        else cout<<0;
    }else{
        cout<<"00";
    }
    return 0;
}