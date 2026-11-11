#include<bits/stdc++.h>

#define lowbit(x) (x&-x)
#define int long long

using namespace std;

namespace cyan
{
    constexpr int N=5e2+2;

    inline int read()
    {
        int x=0;bool f=0;
        char ch=getchar();
        while(ch<'0' || ch>'9') f^=ch=='-',ch=getchar();
        while(ch<='9' && ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
        return f?-x:x;
    }

    inline int min(int a, int b) {return a<b?a:b;}

    inline int max(int a, int b) {return a>b?a:b;}
}

using namespace cyan;

int T;
int c,n,m;
int a[N];
int f[N][2];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c=read();T=read();
    while(T--)
    {
        n=read();m=read();
        int ans=0;
        for(int i=1;i<=n;i++) a[i]=read();a[n+1]=1e12;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++) f[j][0]=f[j][1]=1e12;
            f[i][0]=0;
            for(int j=i;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                {
                    if(a[k]-a[j]>m) break;
                    if(a[k+1]-a[j]<=m) f[k][1]=min(f[k][1], f[j][0]+1);
                    f[k][0]=min(f[j][0]+1, f[k][0]);f[k][1]=min(f[j][1]+1, f[k][1]);
                }
            for(int j=i;j<=n;j++)
                if(f[j][0]==f[j][1] && f[j][0]!=1 && f[j][0]!=1e12) ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}
