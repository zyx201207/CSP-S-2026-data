#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
struct ww
{
    int bh,w;
}f[500005];
struct node
{
    int k,a[40005],t[40005];
}p[505];
struct xxyy
{
    int x,y;
}l[100005];
signed main(void)
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>f[i].w;
        f[i].bh=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].k;
        for(int j=1;j<=p[i].k;j++)cin>>p[i].a[j]>>p[i].t[j];
    }
    for(int i=1;i<=q;i++)cin>>l[i].x>>l[i].y;
    for(int i=1;i<=q;i++)
    {
        int minn=999999999999999;
        for(int j=1;j<=n;j++)
        {
            int sum=f[p[j].a[1]].w+f[p[j].a[p[j].k]].w;
            for(int e=1;e<=p[j].k;e++)sum+=p[j].t[e];
            minn=min(sum,minn);
        }
        cout<<minn<<"\n";
    }
    return 0;
}
