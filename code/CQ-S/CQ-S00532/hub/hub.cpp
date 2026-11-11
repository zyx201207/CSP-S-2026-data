#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<assert.h>
#include<ctime>
#include<vector>
#define int long long
typedef long long LL;
#define PII pair<int, int>
using namespace std;
bool st_m;
namespace Read{
    inline int read(){
        int f = 0, d = 1; char op;
        while(op = getchar(), !isdigit(op)) if(op == '-') d = - 1;
        while(isdigit(op)) f = (f << 1) + (f << 3) + (op ^ 48), op = getchar();
        return f * d;
    }
} using namespace Read;
namespace Bule13{
    const int N = 1e6 + 10;
    int n, K, ans; PII tmp;
    int h[N], ne[2 * N], e[2 * N], idx;
    PII len[N];
    int temp[N], idx_temp;
    int t[N], idx_t;
    int val1[N], val2[N];
    void add(int x, int y){e[ ++ idx] = y, ne[idx] = h[x], h[x] = idx; }
    void dfs(int u, int last){
        PII maxx = {0, u}, maxx2 = {0, u};
        for(int i = h[u]; i != - 1; i = ne[i]){
            if(e[i] != last){
                dfs(e[i], u);
                if(len[e[i]].first + 1 >= maxx.first){
                    maxx2 = maxx;
                    maxx = {len[e[i]].first + 1, len[e[i]].second};
                }
                else if(len[e[i]].first + 1 >= maxx2.first){
                    maxx2 = {len[e[i]].first + 1, len[e[i]].second};
                }
            }
        }
        if(maxx.first + maxx2.first >= ans){
            ans = maxx.first + maxx2.first; tmp = {maxx.second, maxx2.second};
        }
        len[u] = maxx;
    }
    bool dfs2(int u, int last){
        bool flag = false;
        for(int i = h[u]; i != - 1; i = ne[i]){
            if(e[i] != last){
                flag |= dfs2(e[i], u);
            }
        }
        if(u == tmp.second) flag = true;
        if(flag) temp[ ++ idx_temp] = u;
        return flag;
    }
    void dfs3(int u, int last){
        len[u] = {0, u};
        for(int i = h[u]; i != - 1; i = ne[i]){
            if(e[i] != last){
                dfs3(e[i], u);
                if(len[e[i]].first + 1 >= len[u].first){
                    len[u] = {len[e[i]].first + 1, len[e[i]].second};
                }
            }
        }
        t[ ++ idx_t] = len[u].first;
    }
    inline bool check(int x){
        int count = 0;
        for(int i = 1; i <= idx_t; i ++ ) if(t[i] >= x) count ++ ;
        int L = idx_temp + 1, R = 0;
        for(int i = 1; i < idx_temp; i ++ ){
            int now = temp[i];
            if(len[now].first <= x) L = min(L, i + (x - len[now].first)), R = max(R, i - (x - len[now].first));
            else L = min(L, i), R = max(R, i);
            // cout<<L<<' '<<R<<endl;
            if(L <= R) val1[i] = R - L + 1;
            else val1[i] = 1;
        }
        L = idx_temp + 1, R = 0;
        for(int i = idx_temp; i >= 2; i -- ){
            int now = temp[i];
            if(len[now].first <= x) L = min(L, i + (x - len[now].first)), R = max(R, i - (x - len[now].first));
            else L = min(L, i), R = max(R, i);
            if(L <= R) val2[i - 1] = R - L + 1;
            else val2[i - 1] = 1;
        }
        for(int i = 1; i < idx_temp; i ++ ){
            if(val1[i] + val2[i] + count <= K){
                // cout<<val1[i]<<endl;
                return true;
            }
        }
        return false;
    }
    void sol(){
        n = read(), K = read(); ans = 0; tmp = {1, 1}; idx_temp = idx_t = 0;
        for(int i = 1; i <= n; i ++ ) h[i] = - 1; idx = 0;
        int x, y; for(int i = 1; i < n; i ++ ) x = read(), y = read(), add(x, y), add(y, x);
        //找直径
        dfs(1, - 1);
        dfs2(tmp.first, - 1);
        // for(int i = 1; i <= idx_temp; i ++ ) cout<<temp[i]<<' '; cout<<'\n';
        temp[0] = temp[idx_temp + 1] = - 1;
        for(int i = 1; i <= idx_temp; i ++ ){
            int now = temp[i]; len[now] = {0, now};
            for(int j = h[now]; j != - 1; j = ne[j]){
                if(e[j] != temp[i - 1] && e[j] != temp[i + 1]){
                    dfs3(e[j], now);
                    len[now].first = max(len[now].first, len[e[j]].first + 1);
                }
            }
        }
        // for(int i = 1; i <= n; i ++ ) cout<<len[i].first<<' '; cout<<'\n';
        // check(0);
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid; else l = mid + 1;
        }
        cout<<l<<'\n';
    }
    signed main(){
        read(); int T = read(); while(T -- ) sol();
        return 0;
    }
}
bool ed_m;
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    Bule13::main();
    // cerr<<"time:"<<(double)clock() / CLOCKS_PER_SEC<<"\nmemory:"<<(&st_m - &ed_m) / 1024.0 / 1024.0<<'\n';
    return 0;
}
/*
g++ hub.cpp -o a -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000 && .\a.exe < a.in > a.out

fc hub.out hub.ans

g++ hub.cpp -o a -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000
.\a.exe < hub\hub1.in > a.out && fc a.out hub\hub1.ans
.\a.exe < hub\hub2.in > a.out && fc a.out hub\hub2.ans
.\a.exe < hub\hub3.in > a.out && fc a.out hub\hub3.ans
.\a.exe < hub\hub4.in > a.out && fc a.out hub\hub4.ans
.\a.exe < hub\hub5.in > a.out && fc a.out hub\hub5.ans

finish:17:49

*/