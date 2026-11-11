#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int, int>
#define x first
#define y second
#define debug() puts("----------")
#define rd read()
#define gc getchar()
#define U(i, x, y) for(re int (i) = (x); (i) <= (y); ++ (i))
#define UU(i, x, y) for(re int (i) = (x); (i) < (y); ++ (i))
#define D(i, x, y) for(re int (i) = (x); (i) >= (y); -- (i))
#define DD(i, x, y) for(re int (i) = (x); (i) > (y); -- (i))

namespace yzqwq{
    il int read(){
        int x = 0, f = 1; char ch = gc;
        while(ch < '0' || ch > '9'){
            if(ch == '-') f = -1;
            ch = gc;
        }
        while(ch >= '0' && ch <= '9'){
            x = (x << 1) + (x << 3) + (ch ^ 48);
            ch = gc;
        }
        return x * f;
    }
    il int qmi(int a, int b, int mod){
        int res = 1;
        while(b){
            if(b & 1) res = res * a % mod;
            a = a * a % mod, b >>= 1;
        }
        return res;
    }
    il int gcd(int a, int b){
        if(!b) return a;
        return gcd(b, a % b);
    }
    mt19937 rnd(time(0));
}
using namespace yzqwq;

bool f1;
const int N = 2e6 + 10;
int n, d;
int x[N];
int c1[N], c2[N], d1[N], R[N];
int lc[N];
bool vis[N], st[N];
int res;
int f[N][22];
int s1[N], s2[N];
bool f2;

il void solve(int cid){
    n = rd, d = rd;
    U(i, 1, n) x[i] = rd;
    {
        res = 0;
        U(i, 0, n + 1){
            vis[i] = 0;
            s1[i] = s2[i] = 0;
            UU(j, 0, 22) f[i][j] = 0;
        }
    }
    R[n + 1] = n;
    D(i, n, 1){
        R[i] = R[i + 1];
        while(x[R[i]] - x[i] > d) --R[i];
    }
    {
        U(i, 1, n){
            st[i] = 0;
            if(i >= 2 && R[i - 2] == R[i]) st[i] = 1;
        }
        D(i, n, 1){
            if(R[i] == i){
                if(st[i]) c2[i] = i;
                else c2[i] = n + 1;
            }
            else{
                c2[i] = c2[R[i]];
                if(st[R[i]]) c2[i] = R[i];
            }
        }

        U(i, 1, n){
            st[i] = 0;
            if(i >= 2 && R[i - 1] == R[i]) st[i] = 1;
        }
        D(i, n, 1){
            if(R[i] == i){
                if(st[i]) c1[i] = i, d1[i] = n + 1, lc[i] = i;
                else c1[i] = n + 1, d1[i] = n + 1, lc[i] = n + 1;
            }
            else{
                c1[i] = c1[R[i]];
                d1[i] = d1[R[i]];
                lc[i] = lc[R[i]];
                if(st[R[i]]) d1[i] = c1[i], c1[i] = R[i], lc[i] = i;
            }
        }
    }
    U(i, 1, n) f[i][0] = R[i];
    UU(j, 1, 22) U(i, 1, n) f[i][j] = f[f[i][j - 1]][j - 1];
    U(u, 1, n){
        if(R[u] == u) continue;
        {
            if(c1[u] >= R[u]){
                res += max(0ll, R[R[u] - 1] - max(R[R[u] - 2] + 1, R[u] + 1) + 1);
            }
            int pk = R[u];
            D(j, 21, 0){
                int pk_ = f[pk][j];
                if(c1[u] >= pk_) pk = pk_;
            }
            if(pk != R[u]){
                ++ s1[R[u]];
                if(R[pk] != pk){
                    -- s1[pk];
                }
            }
            while(R[pk] != pk && c1[u] >= pk) pk = R[pk];
            if(c1[u] >= pk) continue;
            if(lc[u] != u && R[lc[u] - 1] >= R[lc[u]] - 1) continue;
            int pk1 = u, pk2 = u;
            D(j, 21, 0){
                int pk1_ = f[pk1][j];
                int pk2_ = f[pk2][j];
                if(c2[u] >= pk1_) pk1 = pk1_;
                if(d1[u] >= pk2_) pk2 = pk2_;
            }
            int Pk = min(pk1, pk2);
            if(c1[u] < pk && c2[u] >= Pk && d1[u] >= Pk){
                ++ s2[pk];
                if(R[Pk] != Pk){
                    -- s2[R[Pk]];
                }
            }
        }
        /*
        int pk = R[u];
        while(1){
            // if(c1[u] >= pk){
                // res += max(0ll, R[pk - 1] - max(R[pk - 2] + 1, pk + 1) + 1);
                // if(max(0ll, R[pk - 1] - max(R[pk - 2] + 1, pk + 1) + 1) >= 1){
                //     cout << u <<" " << max(R[pk - 2] + 1, pk + 1) <<" "<<R[pk - 1]<<"\n";
                // }   
            // }
            if(c2[u] >= pk && c1[u] < pk && pk <= d1[u]){
                res += max(0ll, R[pk] - max(pk, R[pk - 1]));
                // if(R[pk] >= max(pk,R[pk - 1]) + 1){
                //     cout << u <<" "<< " "<<max(pk, R[pk-1])+1<<" "<<R[pk]<<"\n";
                // }
            }
            if(R[pk] == pk) break; 
            pk = R[pk];
        }
        */
    }
    U(u, 1, n){
        int pk = R[u];
        if(pk != u){
            if(R[u - 1] < pk - 1){
                // cout << u <<" " <<pk<<" "<< s1[u]<<"Ddd\n";
                res += max(0ll, R[pk - 1] - max(R[pk - 2] + 1, pk + 1) + 1) * s1[u];
            }
        }
        res += max(0ll, R[u] - max(u, R[u - 1])) * s2[u];
        s1[R[u]] += s1[u];
        s2[R[u]] += s2[u];
    }
    cout << res << "\n";
    return ;
}

signed main(){
    // cout<<(&f1-&f2)/1024/1024;
    // return 0;
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c = rd, t = rd,cid=0; while(t --){
        solve(++cid);
    }
    return 0;
}
