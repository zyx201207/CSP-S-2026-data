#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _iter(it,a) for (auto it=a.begin();it!=a.end();++it)
#define _riter(it,a) for (auto it=a.rbegin();it!=a.rend();++it)
#define _all(a) (a).begin(),(a).end()
#define _rall(a) (a).rbegin(),(a).rend()

#define i32 signed
#define i64 long long
#define u32 unsigned
#define u64 unsigned long long

typedef pair<int,int> pii;

const int N=1000005;
const int M=2000005;
const int inf=1e9;

int c,T,n,k;
int e[M],ne[M],h[N],tot;

inline void add(int a,int b) {
    e[tot]=b,ne[tot]=h[a],h[a]=tot++;
}

namespace SOLVE1 {
    bool flag[N];
    bool vis[N];

    inline int dfs(int u,int fa,int d) {
        if (flag[u]) return d;
        int res=inf;
        _graph(i,u) {
            if (e[i]==fa) continue;
            res=min(res,dfs(e[i],u,d+1));
        }
        return res;
    }

    inline void dfs2(int u,int fa) {
        vis[u]=true;
        _graph(i,u) {
            if (e[i]==fa) continue;
            if (flag[e[i]]) dfs2(e[i],u);
        }
    }

    inline void solve() {
        int ans=inf;
        _rep(sta,1,(1<<n)-1) {
            _rep(j,0,n-1) if ((sta>>j)&1) flag[j+1]=1; else flag[j+1]=0;
            int cnt=0;
            _rep(j,1,n) if (flag[j]) cnt++;
            if (cnt!=k) continue;
            _rep(j,1,n) vis[j]=false;
            cnt=0;
            _rep(j,1,n) if (flag[j] && !vis[j]) {
                cnt++;
                dfs2(j,0);
            }
            if (cnt>2) continue;
            int mx=0;
            _rep(j,1,n) mx=max(mx,dfs(j,0,0));
            ans=min(ans,mx);
        }
        printf("%d\n",ans);
    }
}

int main() {
    // FRR("hub2.in");
    // FRW("my.out");
    FRR("hub.in");
    FRW("hub.out");
    scanf("%d %d",&c,&T);
    while (T--) {
        scanf("%d %d",&n,&k);
        _rep(i,1,n) h[i]=-1; tot=0;
        _rep(i,1,n-1) {
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b),add(b,a);
        }
        if (n<=10) {
            SOLVE1::solve();
        }
    }
    return 0;
}

/*
18:17 done O((n^2)*(2^n))
*/