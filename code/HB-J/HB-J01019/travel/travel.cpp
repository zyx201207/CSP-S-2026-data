#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a,b;
    string c,d;
    //this made me think of sleep talk metropolis
    //1. in the same car ->a==b->1 else 0
    //2. same row ->if same car,c0,c1==d0,d1->1 else 0
    //3. same side ->if same row, if D,c/d[2]+100,if F,+99; d[3]-c[3]<=2?
    //4. d[3]-c[3]<=1?
    cin>>a>>c>>b>>d;
    if (c[2]=='D')
        c[2]='Y';
    if (d[2]=='D')
        d[2]='Y';
    if (c[2]=='F')
        c[2]='Z';
    if (d[2]=='F')
        d[2]='Z';
    if (a!=b)
    {
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if ((c[0]!=d[0])||(c[1]!=d[1]))
    {
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if (abs(d[2]-c[2])>2)
    {
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if (abs(d[2]-c[2])>1)
    {
        cout<<"0";
        return 0;
    }
    cout<<"1";
    return 0;
    //0920
    //special thanks: zxc dzd
}
