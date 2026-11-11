#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b=true;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(a2[0]==b2[0]&&a2[1]==b2[1]&&b){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    char a=a2[2],b=b2[2];
    if(a2[2]=='A') n=1;
    if(a2[2]=='B') n=2;
    if(a2[2]=='C') n=3;
    if(a2[2]=='D') n=5;
    if(a2[2]=='F') n=6;
    if(b2[2]=='A') m=1;
    if(b2[2]=='B') m=2;
    if(b2[2]=='C') m=3;
    if(b2[2]=='D') m=5;
    if(b2[2]=='F') m=6;
    int j,k;
    if(n>3&&b){
        j=1;
    }else{
        j=0;
    }
    if(m>3){
        k=1;
    }else{
        k=0;
    }
    if((j==k)&&b){
        cout<<"1";
    }else{
      cout<<"0";
    }
    if(abs(n-m)==1){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}