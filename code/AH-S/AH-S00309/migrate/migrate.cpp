#include <bits/stdc++.h>
#define filename "migrate"
using namespace std;

#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

template<class T> bool vmax(T &a, const T &b) { return b > a ? (a = b, 1) : 0; }
template<class T> bool vmin(T &a, const T &b) { return b < a ? (a = b, 1) : 0; }

const int N = 2e6 + 5;

int qpow(int a, int b, int P) {
    int res = 1;
    while(b) {
        if(b & 1) res = 1ll * res * a % P;
        a = 1ll * a * a % P, b >>= 1;
    }
    return res;
}

signed Case;

int n;
long long d, x[N], tmpx[N];

int pre[N], nxt[N];

namespace sub1 {
    long long solve(long long *x, int n) {
        upw(i, 0, n + 1) pre[i] = 0, nxt[i] = n + 1;
        {
            int p = 0;
            x[0] = x[1], x[n + 1] = x[n];
            upw(i, 1, n) {
                while(p < i && x[i] - x[p] > d) ++p;
                pre[i] = p;
                assert(pre[i] < i);
            }
            pre[n + 1] = pre[n];

            p = n + 1;
            dnw(i, n, 1) {
                while(p > i && x[p] - x[i] > d) --p;
                nxt[i] = p;
                assert(nxt[i] > i);
            }
        }
        long long cnt = 0;
        // upw(i, 1, n) cerr << pre[i] << ' ' << nxt[i] << '\n';
        upw(i, 1, n) {
            upw(j, i + 1, n) {
                vector<int> v1, v2;
                for(int x = i; x < j; x = nxt[x]) v1.push_back(x);
                for(int x = j; x > i; x = pre[x]) v2.push_back(x);
                if(v1.back() == j) continue;
                v1.push_back(j), v2.push_back(i);
                sort(all(v1)), sort(all(v2));
                assert(v1.size() == v2.size());
                if(v1 == v2) continue;
                int f = 0;
                upw(i, 0, (int)v1.size() - 1) if(v1[i] != v2[i]) {
                    if(abs(v1[i] - v2[i]) > 1) {
                        f = 0;
                        break;
                    }
                    else {
                        if(f) {
                            f = 0;
                            break;
                        }
                        f = 1;
                    }
                }
                if(!f) continue;
                cnt += f;
                // cerr << i << ' ' << j << ": ";
                // for(auto i : v1) cerr << i << ' '; cerr << "      ";
                // for(auto i : v2) cerr << i << ' '; cerr << "      "; cerr << '\n';
            }
        }
        // cerr << "meow " << n << '\n';
        // cerr << '\n';
        return cnt;
    }
}

const int P1 = 998244353, P2 = 1000000009;
const int B1 = 993244853, B2 = 1000000007;
int pw1[N], pw2[N];
int ipw1[N], ipw2[N];                   ////////////////////////////////////////////////////////////////////////////////////////
namespace sub2 {

    int n;
    struct tree {
        int fl;
        vector<int> G[N];
        int dep[N];
        pii gethash(int u, int v) {
            long long h1 = fl ? tb1[u] - 1ll * tb1[v] * pw1[dep[u] - dep[v]] : 1ll * (tb1[u] - tb1[v]) * ipw1[dep[v]];
            long long h2 = fl ? tb2[u] - 1ll * tb2[v] * pw2[dep[u] - dep[v]] : 1ll * (tb2[u] - tb2[v]) * ipw2[dep[v]];
            h1 %= P1, h2 %= P2;
            if(h1 < 0) h1 += P1;
            if(h2 < 0) h2 += P2;
            return {(int)h1, (int)h2};
        }
        
        int par[N], val[N];
        int anc[22][N];
        int L[N], R[N], num;
        int tb1[N], tb2[N];
        
        void DFS(int u, int fa) {
            dep[u] = dep[fa] + 1, par[u] = fa;
            if(fl) {
                tb1[u] = (1ll * tb1[fa] * B1 + u) % P1;
                tb2[u] = (1ll * tb2[fa] * B2 + u) % P2;
            }
            else {
                tb1[u] = (tb1[fa] + 1ll * u * pw1[dep[u]]) % P1;
                tb2[u] = (tb2[fa] + 1ll * u * pw2[dep[u]]) % P2;
            }
            L[u] = ++num;
            int cnt = 0;
            for(auto v : G[u]) {
                ++cnt;
                val[v] = val[u] + cnt;
                DFS(v, u);
            }
            R[u] = num;
        }
        void init(int n, int *p, int rt, int fl) {
            num = 0;
            this->fl = fl;
            upw(i, 0, n + 1) G[i].clear();
            upw(i, 1, n) if(p[i] != i) G[p[i]].push_back(i);
            if(fl) upw(i, 0, n + 1) sort(all(G[i]));
            else upw(i, 0, n + 1) sort(all(G[i]), greater<int>());
            upw(i, 1, n) cerr << i << ": " << p[i] << '\n'; cerr << '\n';

            tb1[rt] = tb2[rt] = 0;
            val[rt] = 1;
            DFS(rt, rt);
            upw(i, 1, n) cerr << val[i] << ' '; cerr << '\n';
            upw(i, 1, n) anc[0][i] = p[i];
            upw(k, 1, 21) upw(u, 0, n + 1) anc[k][u] = anc[k - 1][anc[k - 1][u]];
        }
        int iss(int x, int y) {
            return L[y] <= L[x] && R[x] <= R[y];
        }
    } tr1, tr2;

    long long solve(long long *x, int n) {
        sub2::n = n;
        upw(i, 0, n + 1) pre[i] = 0, nxt[i] = n + 1;
        {
            int p = 1;
            upw(i, 1, n) {
                while(p < i && x[i] - x[p] > d) ++p;
                pre[i] = p;
                // assert(pre[i] < i);
            }
            // pre[n + 1] = pre[n];

            p = n;
            dnw(i, n, 1) {
                while(p > i && x[p] - x[i] > d) --p;
                nxt[i] = p;
                // assert(nxt[i] > i);  
            }
            // nxt[0] = nxt[1];
        }
        tr1.init(n, pre, 1, 1);
        tr2.init(n, nxt, n, 0);

        long long ans = 0;
        upw(i, 1, n - 1) {
            int lv = 0;
            {
                int u = pre[i];
                int ou = pre[i];
                dnw(k, 21, 0) {
                    int x = tr1.anc[k][u];
                    cerr << ou << ' ' << x << "       " << nxt[x] << ' ' << i + 1 << '\n';
                    if(tr2.iss(x, i + 1) && tr1.gethash(ou, x) == tr2.gethash(nxt[x], i + 1)) {
                        u = x;
                    }
                }
                cerr << "du " << u << ' ' << i << '\n';
                if(tr2.iss(u, i + 1)) {
                    if(u == 1) {
                        lv = tr2.val[u] - tr2.val[i + 1];
                    }
                    else {
                        lv = tr2.val[nxt[u]] - tr2.val[i + 1];
                    }
                }
            }
            int rv = 0;
            {
                int u = nxt[i + 1];
                int ou = nxt[i + 1];
                dnw(k, 21, 0) {
                    int x = tr2.anc[k][u];
                    if(tr1.iss(x, i) && tr2.gethash(ou, x) == tr1.gethash(pre[x], i)) {
                        u = x;
                    }
                }
                if(tr1.iss(u, i)) {
                    if(u == n) {
                        rv = tr1.val[u] - tr1.val[i];
                    }
                    else {
                        rv = tr1.val[pre[u]] - tr1.val[i];
                    }
                }
                cerr << "du " << u << ' ' << i + 1 << '\n';
            }
            cerr << "meow " << i << ": " << lv << ' ' << rv << '\n';
            ans += 1ll * lv * rv;
        }
        return ans;
    }
}

void WaterM() {
    scanf("%d%lld", &n, &d);
    upw(i, 1, n) scanf("%lld", &x[i]), tmpx[i] = x[i];
    int l = 0;
    long long ans = 0;
    upw(i, 1, n) {
        // cerr << "????? " << x[i] - x[i - 1] << ' ' << d << '\n';
        if(i == 1 || x[i] - x[i - 1] > d) l = i;
        if(i == n || x[i + 1] - x[i] > d) {
            upw(j, l, i) tmpx[j] = x[j];
            if(Case <= 6) ans += sub1::solve(tmpx + l - 1, i - l + 1);//, cerr << l << ' ' << i << '\n';
            else 
                ans += sub2::solve(tmpx + l - 1, i - l + 1);
        }
    }
    printf("%lld\n", ans);
    // cerr << "\n\n\n";
}

signed main() {
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
    signed _ = 1;
    scanf("%d%d", &Case, &_);

    pw1[0] = pw2[0] = ipw1[0] = ipw2[0] = 1;
    int iB1 = qpow(B1, P1 - 2, P1);
    int iB2 = qpow(B2, P2 - 2, P2);
    upw(i, 1, N - 1) {
        pw1[i] = pw1[i - 1] * 1ll * B1 % P1;
        pw2[i] = pw2[i - 1] * 1ll * B2 % P2;
        ipw1[i] = ipw1[i - 1] * 1ll * iB1 % P1;
        ipw2[i] = ipw2[i - 1] * 1ll * iB2 % P2;
    }

    upw(round, 1, _) WaterM();
    return 0;
}