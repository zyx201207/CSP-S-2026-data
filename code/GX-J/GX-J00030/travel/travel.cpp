#include<bits/stdc++.h>
using namespace std;
string x1,x2,r1,r2;
char x,r;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s=0,m=0,f=1,p=1;
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1) cout<<"1";
    else {cout<<"0000"; return 0;}
    for(int i=0;i<2;++i)
           s=s*10+(r2[i]-48);
    for(int i=0;i<2;++i)
            m=m*10+(x2[i]-48);
       // cout<<s<<m;
    if(s==m) cout<<"1";
    else {cout<<"000"; return 0;}
    if(r2[2]>='A'&&r2[2]<='C'&&x2[2]>='A'&&x2[2]<='C') cout<<"1";
    else if(r2[2]>='D'&&r2[2]<='F'&&x2[2]>='D'&&x2[2]<='F') {cout<<"11"; return 0;}
    else {cout<<"00"; return 0;}
        if(r2[2]=='A'&&x2[2]=='B') cout<<"1";
    else if(r2[2]=='B'&&x2[2]=='C') cout<<"1";
    else cout<<"0";
    return 0;
}
