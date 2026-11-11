#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int ans=0;
struct N
{
    int a;
    int time;
}s[505][505];
struct Plan
{
    int x;
    int y;
}plan[100010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int _;
        cin>>_;
        for(int j=1;j<=2*_;j++)
        {
            cin>>s[i][j].a>>s[i][j].time;
        }
        _=0;
    }
    for(int i=2+n;i<=q;i++)
    {
        cin>>plan[i].x>>plan[i].y;
    }


    for(int i=1;i<=q;i++)
    {
        ans=0;
        int x1=1,y1=2;
        ans+=w[plan[i].x];
        for(int j=plan[i].x;j<=plan[i].y;j++)
        {
            if(s[x1][y1].a!=j) ans+=s[x1+1][y1+1].a;
        }
        cout<<ans<<endl;
    }
    return 0;
}
