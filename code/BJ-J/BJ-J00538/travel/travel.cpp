#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rs,xc,xs;
    cin>>rc>>rs>>xc>>xs;
    bool a=0,b=0,c=0,d=0;
    if(rc==xc) a=1;
    if(rs[0]==xs[0]&&rs[1]==xs[1]) b=1;
    if(rs[2]=='A'||rs[2]=='B'||rs[2]=='C')
    {
        if(xs[2]=='A'||xs[2]=='B'||xs[2]=='C')
            c=1;
    }
    else if(xs[2]=='D'||xs[2]=='F')
        c=1;
    if(rs[2]=='A')
    {
        if(xs[2]=='B') d=1;
    }
    if(rs[2]=='B')
    {
        if(xs[2]=='A'||xs[2]=='C') d=1;
    }
    if(rs[2]=='C')
    {
        if(xs[2]=='B') d=1;
    }
    if(rs[2]=='D')
    {
        if(xs[2]=='F') d=1;
    }
    if(rs[2]=='F')
    {
        if(xs[2]=='D') d=1;
    }
    if(a==1) cout<<1;
    else cout<<0;
    if(a==1&&b==1) cout<<1;
    else cout<<0;
    if(a==1&&b==1&&c==1) cout<<1;
    else cout<<0;
    if(a==1&&b==1&&c==1&&d==1) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}