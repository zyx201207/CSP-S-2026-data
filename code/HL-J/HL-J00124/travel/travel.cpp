#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    bool b1=0,b2=0,b3=0;
    if(c1==c2){
        cout<<1;
        b1=1;
    }
    else cout<<0;
    string sr="",sx="";
    for(int i=0;i<=1;i++){
        sr+=s1[i];
        sx+=s2[i];
    }
    if(sr==sx&&b1==1){
        cout<<1;
        b2=1;
    }
    else cout<<0;
    char sr_side=s1[2],sx_side=s2[2];
    if(((sr_side>='A'&&sr_side<='C'&&sx_side>='A'&&sx_side<='C')||(sr_side>='D'&&sr_side<='E'&&sx_side>='D'&&sx_side<='E'))&&(b1==1&&b2==1)){
        cout<<1;
        b3=1;
    }
    else cout<<0;
    int t=abs(sr_side-sx_side);
    if((b1==1&&b2==1&&b3==1)&&(t==1)){
        cout<<1;
    }
    else cout<<0;
    return 0;
}

