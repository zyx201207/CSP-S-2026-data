#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=505,M=5e5+5,P=1e9+7;
const ll inf=1e18;

int rd()
{
    int x=0,y=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            y=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*y;
}

void wt(ll x,char c='~')
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>=10)
        wt(x/10);
    putchar(x%10+'0');
    if(c!='~')
        putchar(c);
}

void setmin(ll &x,ll y)
{
    if(y<x)
        x=y;
}

int n,m,d,q,w[M];
ll f[N][N];
vector<pii> a[M];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int op=rd();n=rd();m=rd();d=rd();q=rd();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                f[i][j]=inf;
    for(int i=1;i<=m;i++)
        w[i]=rd();
    for(int i=1;i<=n;i++)
    {
        int k=rd();
        while(k--)
        {
            int x,y;
            x=rd();y=rd();
            for(auto p:a[x])
                setmin(f[i][p.first],1ll*y+p.second),setmin(f[p.first][i],1ll*y+p.second);
            a[x].push_back({i,y});
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                setmin(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        int x,y;
        x=rd(),y=rd();
        ll mn=inf;
        for(auto p1:a[x])
            for(auto p2:a[y])
                setmin(mn,f[p1.first][p2.first]+p1.second+p2.second);
        mn+=w[x]+w[y];
        wt(mn,'\n');
    }
    return 0;
}