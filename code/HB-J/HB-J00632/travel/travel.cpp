#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool tc=false;
    bool car=false;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        car=true;
    }
    else cout<<0;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&car==true){
        cout<<1;
        tc=true;
    }
    else cout<<0;
    bool yb=false;//tongyice
    int wz1=s1[2];
    int wz2=s2[2];
    if(tc==true&&car==true){
        if((wz1=='A'||wz1=='B'||wz1=='C')&&(wz2=='A'||wz2=='B'||wz2=='C')){
            cout<<1;
            yb=true;
        }
        else if((wz1=='D'||wz1=='F')&&(wz2=='D'||wz2=='F')){
            cout<<1;
            yb=true;
        }
        else cout<<0;
    }
    else cout<<0;
    if(yb==true&&car==true){
        if(wz1+1==wz2||wz1-1==wz2)cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
