#include<bits/stdc++.h>
#define int long long
#define maxn 500006
#define maxm 505
#define inf 0x3f3f3f3f3f3f3f3f
#define pii std::pair<int,int>
#define fi first
#define sc second
int n,m,d,q,a[maxn],ans,w[maxn],f[maxm][maxm];
std::vector<pii>c[maxn];
inline int read()
{
    int x = 0,f = 1;char ch = getchar();
    while(ch<'0'||ch>'9')f = ch == '-'?-f:f,ch = getchar();
    while(ch>='0'&&ch<='9')x = (x<<3)+(x<<1)+(ch^'0'),ch = getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x = -x;
    static char sta[35];int top = 0;
    do sta[top++] = x%10,x/=10;while(x);
    while(top)putchar(sta[--top]^'0');
    putchar('\n');
}
inline void min(int&x,int y){if(x>y)x = y;}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(),n = read(),m = read(),d = read(),q = read();
    for(int i = 1;i<=m;++i)w[i] = read();
    for(int i = 1,k;i<=n;++i)
    {
        k = read();
        for(int j = 1,pos;j<=k;++j)
            pos = read(),c[pos].push_back(pii(i,read()));
    }
    for(int i = 1;i<=n;++i)memset(f[i]+1,0x3f,sizeof(int)*n),f[i][i] = 0;
    for(int i = 1;i<=m;++i)
        for(pii u:c[i])for(pii v:c[i])
            min(f[u.fi][v.fi],u.sc+v.sc);
    for(int k = 1;k<=n;++k)
        for(int i = 1;i<=n;++i)
            for(int j = 1;j<=n;++j)
                min(f[i][j],f[i][k]+f[k][j]);
    //for(int i = 1;i<=n;++i,putchar('\n'))
    //    for(int j = 1;j<=n;++j)printf("%lld ",f[i][j]);
    for(int i = 1,u,v,ans;i<=q;++i)
    {
        u = read(),v = read(),ans = inf;
        for(pii s:c[u])for(pii t:c[v])
            min(ans,f[s.fi][t.fi]+s.sc+t.sc);
        write(ans+w[u]+w[v]);
    }
    return 0;
}
