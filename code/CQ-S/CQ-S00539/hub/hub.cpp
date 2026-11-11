#include<ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
bool ST; namespace furina{
    const int N = 1e6, inf = 0x7fffffff >> 1;

    int n, k;
    struct edge{
        int nxt, to;
    } e[(N << 1) + 10];
    int head[N + 10], cntedge;
    inline void addedge(int u, int v){
        e[++cntedge] = {head[u], v};
        head[u] = cntedge;
    }

    int depth[N + 10], father[N + 10];
    int find(int u, int fa){
        depth[u] = depth[father[u] = fa] + 1;
        int res = u;
        for(int i = head[u]; i; i = e[i].nxt){
            int v = e[i].to;
            if(v == fa)
                continue;
            int w = find(v, u);
            if(depth[res] < depth[w])
                res = w;
        }
        return res;
    }

    int rt;
    int maxdep[N + 10], tag[N + 10], deg[N + 10], dg[N + 10];
    void dfs(int u, int fa){
        depth[u] = depth[father[u] = fa] + 1;
        maxdep[u] = 0;
        for(int i = head[u]; i; i = e[i].nxt){
            int v = e[i].to;
            if(v == fa)
                continue;
            dfs(v, u);
            maxdep[u] = max(maxdep[u], maxdep[v] + 1);
        }
    }

    int stk[N + 10], top;
    int mxdp[N + 10];
    void dfs1(int u, int fa){
        mxdp[u] = 0;
        for(int i = head[u]; i; i = e[i].nxt){
            int v = e[i].to;
            if(v == fa || tag[v])
                continue;
            dfs1(v, u);
            mxdp[u] = max(mxdp[u], mxdp[v] + 1);
        }
    }

    int liml[N + 10], limr[N + 10], ly[N + 10];

    int ans;
    inline bool check(int mid){
        if(ans == mid)
            return true;

        dfs(rt, 0);

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            tag[i] = 0;
            if(maxdep[i] >= mid)
                cnt++, tag[i] = 1;
        }
        if(cnt <= k)//一个连通块
            return true;
        int fnn = cnt - k;
        
        //两个连通块
        //删掉maxdep[i]>=mid的一条链，并且要求这条链上的度数均为2
        for(int i = 1; i <= n; i++){
            deg[i] = 0;
            if(!tag[i])
                continue;
            for(int j = head[i]; j; j = e[j].nxt)
                deg[i] += tag[e[j].to];
        }
        for(int i = 1; i <= n; i++){
            dg[i] = 0;
            if(deg[i] != 2)
                continue;
            for(int j = head[i]; j; j = e[j].nxt)
                dg[i] += deg[e[j].to] == 2;
        }

        for(int s = 1; s <= n; s++){
            if(dg[s] <= 1 && deg[s] == 2){
                top = 0;
                int cur = s, lst = -1;
                while(1){
                    stk[++top] = cur;
                    int flag = 0;
                    for(int i = head[cur]; i; i = e[i].nxt){
                        if(lst == e[i].to || deg[e[i].to] != 2)
                            continue;
                        lst = cur, cur = e[i].to;
                        flag = 1;
                        break;
                    }
                    if(!flag)
                        break;
                }
                if(top < fnn)
                    continue;

                for(int i = 1; i <= top; i++){
                    dfs1(stk[i], 0);
                    int dlt = mid - mxdp[stk[i]];
                    liml[i] = max(1, i - dlt + 1);
                    limr[i] = min(top, i + dlt - 1);
                }

                for(int l = 0; l <= top - fnn + 1; l++)
                    ly[l] = 0;

                for(int i = 1; i <= top; i++){
                    int L = limr[i] - fnn + 1 + 1, R = liml[i] - 1;
                    L = max(L, 1), R = min(R, top - fnn + 1);
                    if(L > R)
                        continue;
                    ly[L]++, ly[R + 1]--;
                }

                for(int l = 1; l <= top - fnn + 1; l++){
                    ly[l] += ly[l - 1];
                    if(!ly[l])
                        return true;
                }
            }
        }
        return false;
    }

    inline void solve(){
        cin >> n >> k;
        for(int i = 1, u, v; i < n; i++){
            cin >> u >> v;
            addedge(u, v), addedge(v, u);
        }

        int x = find(1, 0), y = find(x, 0);

        int L = 0, R = ans = ((depth[y] - 1) >> 1);
        rt = y;
        for(int i = 1; i <= R; i++)
            rt = father[rt];

        while(L < R){
            int mid = (L + R) >> 1;
            if(check(mid))
                R = mid;
            else
                L = mid + 1;
        }

        cout << L << '\n';
    }

    int main(){
        int c, T;
        cin >> c >> T;
        while(T--){
            solve();
            //clear
            cntedge = 0;
            for(int i = 1; i <= n; i++)
                head[i] = 0;
        }
        return 0;
    }
} bool ED;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    furina::main();
    cerr << (1000. * clock() / CLOCKS_PER_SEC) << "ms" << '\n';
    cerr << (abs(&ST - &ED) >> 20) << "mb" << '\n';
    return 0;
}
/*
g++ -o hub hub.cpp -std=c++14 -Wall -O2 -lm -Wl,--stack=2000000000 & .\hub

g++ -o hub hub.cpp -std=c++14 -Wall -O2 -lm -Wl,--stack=2000000000
hub < hub1.in > hub.out & fc hub.out hub1.ans
hub < hub2.in > hub.out & fc hub.out hub2.ans
hub < hub3.in > hub.out & fc hub.out hub3.ans
hub < hub4.in > hub.out & fc hub.out hub4.ans
hub < hub5.in > hub.out & fc hub.out hub5.ans
*/
