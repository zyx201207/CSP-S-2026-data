#include<bits/stdc++.h>
#define int long long
#define maxn 2000006
int T,n,d,a[maxn],f[maxn][2],ans,lft[maxn][2],rgt[maxn][2];
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
namespace bit
{
    int c[maxn];
    inline void insert(int x,int v){while(x<=n)c[x]+=v,x+=-x&x;}
    inline int query(int x){int ret = 0;while(x)ret+=c[x],x^=-x&x;return ret;}
    inline void clear(){memset(c+1,0,sizeof(int)*n);}
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(),T = read();
    while(T--)
    {
        n = read(),d = read(),ans = 0;
        for(int i = 1;i<=n;++i)a[i] = read();
        for(int i = n,r,val;i;--i)
        {
            if(i == 1)lft[i][0] = 1;
            else lft[i][0] = std::upper_bound(a+1,a+1+n,a[i-1]+d)-a-1;
            if(lft[i][0]<i)++lft[i][0];
            rgt[i][0] = std::upper_bound(a+1,a+1+n,a[i]+d)-a-1;
            if(rgt[i][0] == i)f[i][0] = 1;
            else if(rgt[i][0]>lft[i][0])f[i][0] = f[rgt[i][0]][0]+1;
            else f[i][0] = 1;
        }
        for(int i = 1,r,val;i<=n;++i)
        {
            if(i == n)rgt[i][1] = n;
            else rgt[i][1] = std::lower_bound(a+1,a+1+n,a[i+1]-d)-a;
            if(rgt[i][1]>i)--rgt[i][1];
            lft[i][1] = std::lower_bound(a+1,a+1+n,a[i]-d)-a;
            if(lft[i][1] == i)f[i][1] = 1;
            else if(lft[i][1]<rgt[i][1])f[i][1] = f[lft[i][1]][1]+1;
            else f[i][1] = 1;
        }
        for(int i = 1;i<n;++i)if(a[i]+d>a[i+1])
        {
            if(lft[i][1]!=i&&rgt[i+1][0]!=i+1)
            {
                if(lft[rgt[i+1][0]][1] == i&&rgt[lft[i][1]][0] == i+1)
                    ans+=(f[rgt[i+1][0]][0]-1)*(f[lft[i][1]][1]-1);
                if(lft[rgt[i+1][0]][1] == i)
                    ans+=(rgt[i+1][1]-lft[i+1][1])*(f[rgt[i+1][0]][0]-1);
                if(rgt[lft[i][1]][0] == i+1)
                    ans+=(rgt[i][0]-lft[i][0])*(f[lft[i][1]][1]-1);
                ans+=(rgt[i+1][1]-lft[i+1][1])*(rgt[i][0]-lft[i][0]);
                //printf("%d %d %d %d %d\n",ans,(f[rgt[i+1][0]][0]-1)*(f[lft[i][1]][1]-1),(rgt[i+1][1]-lft[i+1][1])*(f[rgt[i+1][0]][0]-1),(rgt[i][0]-lft[i][0])*(f[lft[i][1]][1]-1),(rgt[i+1][1]-lft[i+1][1])*(rgt[i][0]-lft[i][0]));
            }
        }
        write(ans);
        memset(f+1,0,sizeof(int)*n*2);
        bit::clear();
    }
    return 0;
}
