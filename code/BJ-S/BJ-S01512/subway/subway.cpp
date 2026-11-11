#include<bits/stdc++.h>
using namespace std;
long long w[50005],a[505][50005],t[505][1005],x[100005],y[100005],ans=INT_MAX;
long long c,n,m,d,q;
long long b[50005][505],e[505],f[50005],g[50005][505];
long long next1(long long nowz,long long nowl)
{
    return a[nowl][g[nowz][nowl]+1];
}
long long next2(long long nowz,long long nextl)
{
    return a[nextl][g[nowz][nextl]+1];
}
void dfs(long long nowz,long long nowl,long long zdz,long long sum)
{
    if(nowz==zdz)
    {
        ans=min(ans,sum+w[zdz]+t[nowl][nowz]);
        return;
    }
    if(nowz==a[nowl][e[nowl]])return;
    for(int i=1;i<=f[nowz];i++)
    {
        long long nextl=b[nowz][i];
        if(nextl==nowl)
        {
            dfs(next1(nowz,nowl),nowl,zdz,sum);
        }
        else
        {
            dfs(next2(nowz,nextl),nextl,zdz,sum+t[nowl][nowz]+t[nextl][g[nowz][nextl]]);
        }
    }
    return;
}
int main()
{
    long long x,y;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>e[i];
        for(int j=1;j<=e[i];j++)
        {
            cin>>x>>y;
            a[i][j]=x;
            t[i][j]=y;
            f[x]++;
            b[x][f[x]]=i;
            g[x][i]=j;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        for(int j=1;j<=f[x];j++)
        {
            dfs(x,b[x][j],y,w[x]);
        }
        cout<<ans<<endl;
        ans=INT_MAX;
    }

    return 0;
}
