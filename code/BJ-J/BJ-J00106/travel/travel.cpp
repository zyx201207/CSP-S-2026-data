#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,x1,x2;
    cin>>s1>>s2>>x1>>x2;
    string p1="",p2="";
    p1+=s2[0];
    p1+=s2[1];
    p2+=x2[0];
    p2+=x2[1];
    char y1=s2[2],y2=x2[2];
    if(s1==x1)cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(p1==p2)cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(y1=='D'){
        if(y2=='C')cout<<"0";
        else cout<<"1";
    }
    if(y2=='D'){
        if(y1=='C')cout<<"0";
        else cout<<"1";
    }
    else cout<<"1";
    if(y1=='A'){
        if(y2=='B')cout<<"1";
        else cout<<"0";
    }
    if(y1=='B'){
        if(y2=='A'||y2=='C')cout<<"1";
        else cout<<"0";
    }
    if(y1=='C'){
        if(y2=='B')cout<<"1";
        else cout<<"0";
    }
    if(y1=='D'){
        if(y2=='F')cout<<"1";
        else cout<<"0";
    }
    return 0;
}
