#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,a2,n=0,n2=0;
    bool b=false,b2=false,b3=false;
    string z,z2;
    char c,c2;
    cin>>a>>z>>a2>>z2;
    if(a==a2){
        b=true;
        cout<<1;
    }else{
        cout<<0;
    }
    n+=(z[0]-'0')*10+z[1]-'0';
    n2+=(z2[0]-'0')*10+z2[1]-'0';
    c=z[2];
    c2=z2[2];
    if((n==n2)&&(b==true)){
        b2=true;
        cout<<1;
    }else{
        cout<<0;
    }
    if((b2==true)&&((c=='A' && c2=='B') || (c=='B' && c2=='A') || (c=='B' && c2=='C') || (c=='C' && c2=='B') || (c=='D' && c2=='F') || (c=='F' && c2=='D') || (c=='A' && c2=='C') || (c=='C' && c2=='A'))){
        b3=true;
        cout<<1;
    }else{
        cout<<0;
    }
    if((b3==true)&&((c=='A' && c2=='B') || (c=='B' && c2=='A') || (c=='B' && c2=='C') || (c=='C' && c2=='B') || (c=='D' && c2=='F') || (c=='F' && c2=='D'))){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}