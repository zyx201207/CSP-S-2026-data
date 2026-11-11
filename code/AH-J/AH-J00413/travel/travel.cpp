#include<bits/stdc++.h>
using namespace std;
int r1,x1,r,x;
string r2,x2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    r=(r2[0]-'0')*10+(r2[1]-'0');
    x=(x2[0]-'0')*10+(x2[1]-'0');
    if(r==x){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(r2[2]<='C'&&r2[2]>='A'&&x2[2]<='C'&&x2[2]>='A'||r2[2]=='D'&&r2[2]=='F'||x2[2]=='D'&&x2[2]=='F'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(r2[2]=='D'&&x2[2]=='F'||x2[2]=='D'&&r2[2]=='F'||r2[2]=='A'&&x2[2]=='B'||x2[2]=='A'&&r2[2]=='B'||r2[2]=='C'&&x2[2]=='B'||x2[2]=='C'&&r2[2]=='B'){
        cout<<1;
    }else{
        cout<<"0";
        return 0;
    }
    return 0;
}
