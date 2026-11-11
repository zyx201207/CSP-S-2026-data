#include<bits/stdc++.h>

#define lowbit(x) (x&-x)
#define int long long

using namespace std;

namespace cyan
{
    constexpr int N=5e2+2;

    int to[N<<1];
    int head[N];
    int nxt[N<<1];
    int t[N<<1];
    int num=0;

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

    inline void add(int u, int v)
    {
        to[++num]=v;
        nxt[num]=head[u];head[u]=num;return ;
    }

    inline void insert(int u, int v)
    {
        add(u, v);add(v, u);return ;
    }
}

using namespace cyan;

int T;
int c,n,m;

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    c=read();T=read();
    while(T--)
    {
        n=read();m=read();
        int u,v;
        for(int i=1;i<n;i++)
        {
            u=read();v=read();insert(u, v);
        }
        if(m>=n) puts("0");
        else if(m>=n/2) puts("1");
        else if(m==1) cout<<(n+1>>1)<<'\n';
        else puts("2");
    }

    return 0;
}

