#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<1;
    }
    int lr,lx;
    char sr,sx;
    lr=((s1[0]-'0')*10)+((s1[1]-'0')*10);
    lx=((s2[0]-'0')*10)+((s2[1]-'0')*10);
    sr=s1[2];
    sx=s2[2];
    if(lr==lx){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if((sr=='C'&&sx=='D')||(sr=='D'&&sx=='C')){
        cout<<"00";
        return 0;
    }
    else{
        cout<<1;
    }
    if(abs(sr-sx)==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}