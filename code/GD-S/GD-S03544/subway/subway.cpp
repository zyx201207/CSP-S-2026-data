#include<bits/stdc++.h>
using namespace std;
const long long maxn=505,maxm=5e5+5,inf=1e18;
int C,n,m,g,q,h[maxm],t[maxm],p[maxm],cnt,lst[maxm],sum[maxm],o[100],oo;
long long d[maxn][maxn],s[maxm],ans;
void A(int u,int v,int w)
{
    cnt++;
    p[cnt]=v,s[cnt]=w;
    if(!lst[u])lst[u]=h[u]=cnt;
    else t[lst[u]]=cnt,lst[u]=cnt;
}
int rd()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return x;
}
void pt(long long x)
{
    oo=0;
    while(x)o[++oo]=x%10,x/=10;
    while(oo)putchar('0'+o[oo--]);
    putchar('\n');
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(d,0x3f,sizeof(d));
    C=rd(),n=rd(),m=rd(),g=rd(),q=rd();
    for(int i=1;i<=m;i++)sum[i]=rd();
    for(int i=1;i<=n;i++)
    {
        d[i][i]=0;
        int k=rd();
        while(k--)
        {
            int v=rd(),w=rd();
            A(v,i,w);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int u=h[i];u;u=t[u])
        for(int v=t[u];v;v=t[v])
        d[p[u]][p[v]]=d[p[v]][p[u]]=min(d[p[u]][p[v]],s[u]+s[v]);
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--)
    {
        ans=inf;
        int u=rd(),v=rd();
        for(int x=h[u];x;x=t[x])
        for(int y=h[v];y;y=t[y])
        ans=min(ans,s[x]+s[y]+d[p[x]][p[y]]);
        pt(ans+sum[u]+sum[v]);
    }
    return 0;
}