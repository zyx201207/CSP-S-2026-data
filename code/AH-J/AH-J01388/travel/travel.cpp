#include <bits/stdc++.h>
using LL=long long;
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,x1,r2,x2;
    cin>>r1>>r2>>x1>>x2;
    bool b1=0,b2=0,b3=0,b4=0,r=false,x=false;
    if(r1==x1)b1=true;
    if(r2[0]==x2[0]&&r2[1]==x2[1]&&b1)b2=true;
    if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C')r=true;
    if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C')x=true;
    if(r==x&&b1&&b2)b3=true;
    if(abs(r2[2]-x2[2])==1&&b3&&b2&&b1)b4=true;
    cout<<(b1?1:0)<<(b2?1:0)<<(b3?1:0)<<(b4?1:0);
    return 0;
}
