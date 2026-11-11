#include <bits/stdc++.h>
using namespace std;
int p,q,r,n;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1])
    {
        p=1;
    }
    if(p==1&&b[0]==d[0]&&b[1]==d[1])
    {
        q=1;
    }
    if(q==1&&(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))
    {
        r=1;
    }
    if(r==1&&((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')))
    {
        n=0;
    }
    else n=1;
    if(p==0) cout<<"0000";
    if(p==1&&q==0)cout<<"1000";
    if(p==1&&q==1&&r==0) cout<<"1100";
    if(p==1&&q==1&&r==1&&n==0) cout<<"1110";
    if(p==1&&q==1&&r==1&n==1) cout<<"1111";
    return 0;
}


