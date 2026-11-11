#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
int C,T,n,K,dfs1mx,dfs1mxid,fa[MAXN],pth[MAXN],mid,bkt1[MAXN << 1],bkt2[MAXN << 1];
bool ok;
vector <int> g[MAXN];
inline void dfs1(int pos,int dep){
    if(dep > dfs1mx){
        dfs1mx = dep;
        dfs1mxid = pos;
    }
    for(int i = 0;i < g[pos].size();i++){
        int u = g[pos][i];
        if(u != fa[pos]){
            fa[u] = pos;
            dfs1(u,dep + 1);
        }
    }
}
struct solver{
    int mxdep[MAXN],f[MAXN],mn[MAXN];
    inline void dfs2(int pos){
        f[pos] = mxdep[pos] = 0;
        for(int i = 0;i < g[pos].size();i++){
            int u = g[pos][i];
            if(u != fa[pos]){
                fa[u] = pos;
                dfs2(u);
                mxdep[pos] = max(mxdep[pos],mxdep[u] + 1);
                f[pos] += f[u];
            }
        }
        if(mxdep[pos] >= mid){
            f[pos]++;
        }
    }
    inline void dfs3(int pos,int dep,int to1,int to2){
        mn[to2] = min(mn[to2],max(f[pos],1));
        vector <int> premx(g[pos].size() + 1),sufmx(g[pos].size() + 1);
        for(int i = 0;i < g[pos].size();i++){
            int u = g[pos][i];
            premx[i + 1] = max(premx[i],(u == fa[pos]) ? 0 : (mxdep[u] + 1));
        }
        for(int i = (int)g[pos].size() - 1;~i;i--){
            int u = g[pos][i];
            sufmx[i] = max(sufmx[i + 1],(u == fa[pos]) ? 0 : (mxdep[u] + 1));
        }
        for(int i = 0;i < g[pos].size();i++){
            int u = g[pos][i];
            if(u != fa[pos]){
                int nxt1 = to1,nxt2 = to2;
                if(bkt1[n + mid - dep] > nxt1){
                    nxt1 = bkt1[n + mid - dep];
                    nxt2 = bkt2[n + mid - dep];
                }
                int mx = max(premx[i],sufmx[i + 1]);
                if(mx >= mid){
                    nxt1 = dep + 1;
                    nxt2 = u;
                }
                int pre1 = bkt1[n + mx - dep],pre2 = bkt2[n + mx - dep];
                bkt1[n + mx - dep] = dep + 1;
                bkt2[n + mx - dep] = u;
                dfs3(u,dep + 1,nxt1,nxt2);
                bkt1[n + mx - dep] = pre1;
                bkt2[n + mx - dep] = pre2;
            }
        }
    }
    inline void dfs4(int pos,int x,int y){
        vector <int> premx(g[pos].size() + 1),sufmx(g[pos].size() + 1);
        vector <int> presum(g[pos].size() + 1),sufsum(g[pos].size() + 1);
        for(int i = 0;i < g[pos].size();i++){
            int u = g[pos][i];
            premx[i + 1] = max(premx[i],(u == fa[pos]) ? 0 : (mxdep[u] + 1));
            presum[i + 1] = presum[i] + ((u == fa[pos]) ? 0 : f[u]);
        }
        for(int i = (int)g[pos].size() - 1;~i;i--){
            int u = g[pos][i];
            sufmx[i] = max(sufmx[i + 1],(u == fa[pos]) ? 0 : (mxdep[u] + 1));
            sufsum[i] = sufsum[i + 1] + ((u == fa[pos]) ? 0 : f[u]);
        }
        for(int i = 0;i < g[pos].size();i++){
            int u = g[pos][i];
            if(u != fa[pos]){
                int mx = max(premx[i],sufmx[i + 1]),nxt;
                if(mx >= mid){
                    nxt = x + y + 1 + presum[i] + sufsum[i + 1];
                }
                else{
                    nxt = x;
                }
                if(nxt + mn[u] <= K){
                    ok = 1;
                }
                if(mx >= mid){
                    dfs4(u,nxt,0);
                }
                else{
                    dfs4(u,nxt,y + 1);
                }
            }
        }
    }
    inline void clr(){
        for(int i = 1;i <= n;i++){
            mn[i] = K + 1;
        }
    }
}s1,s2,s3;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C >> T;
    while(T--){
        cin >> n >> K;
        for(int i = 1;i <= n;i++){
            g[i].clear();
        }
        for(int i = 1;i < n;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1mx = -1;
        fa[1] = 0;
        dfs1(1,0);
        int rt1 = dfs1mxid;
        dfs1mx = -1;
        fa[rt1] = 0;
        dfs1(rt1,0);
        int rt2 = dfs1mxid;
        int pthtop = 0,u = rt2;
        while(u){
            pth[++pthtop] = u;
            u = fa[u];
        }
        int ans = (pthtop - 1) >> 1;
        int l = 0,r = ans - 1;
        while(l <= r){
            mid = (l + r) >> 1;
            ok = 0;
            if(pthtop & 1){
                int rt = pth[(pthtop + 1) >> 1];
                s1.clr();
                fa[rt] = 0;
                s1.dfs2(rt);
                s1.dfs3(rt,0,0,rt);
                s1.dfs4(rt,0,0);
            }
            s2.clr();
            s3.clr();
            fa[rt1] = 0;
            s2.dfs2(rt1);
            s2.dfs3(rt1,0,0,rt1);
            fa[rt2] = 0;
            s3.dfs2(rt2);
            s3.dfs3(rt2,0,0,rt2);
            int mn = s3.mn[pth[1]];
            for(int i = 2;i <= pthtop;i++){
                mn = min(mn,s3.mn[pth[i]]);
                if(s2.mn[pth[i - 1]] + mn <= K){
                    ok = 1;
                }
            }
            if(ok){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
