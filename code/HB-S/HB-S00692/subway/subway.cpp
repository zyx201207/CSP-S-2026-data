#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

inline int readI(){
    int x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * f;
}
inline ll readL(){
    ll  x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * f;
}
inline void printI(int x){
    if(x < 0) {x = -x; putchar('-');}
    if(x > 9) printI(x / 10);
    putchar(x % 10 + '0');
}
inline void printL(ll x){
    if(x < 0) {x = -x; putchar('-');}
    if(x > 9) printL(x / 10);
    putchar(x % 10 + '0');
}
constexpr int N = 505;
constexpr int M = 5e5 + 5;
int C,n,m,d,q,k[N];
ll floyd[N][N];
struct Node{
    vector<pii> v;
    int k;
}sub[N];
struct Point{
    vector<pii> v;
    ll W;
}p[M];

int st,ed;
void solve(){
    st = readI(); ed = readI();
    ll ans = 1e18,x,y;
    for(int i = 0;i < p[st].v.size();i++) for(int j = 0;j < p[ed].v.size();j++){
        x = p[st].v[i].fi,y = p[ed].v[j].fi;
        ans = min(ans,floyd[x][y] + p[st].v[i].se + p[ed].v[j].se);
    }
    ans += p[st].W + p[ed].W;
    printL(ans); puts("");
}
int main(){ 
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    C = readI(); n = readI(); m = readI(); d = readI(); q = readI();
    for(int i = 1;i <= m;i++) p[i].W = readL();
    memset(floyd,0x3f3f3f3f,sizeof(floyd));
    ll a,t;
    for(int i = 1;i <= n;i++){
        floyd[i][i] = 0;
        sub[i].k = readI();
        for(int j = 1;j <= sub[i].k;j++){
            a = readL(); t = readL();
            sub[i].v.pb(mp(a,t));
            p[a].v.pb(mp(i,t));
        }
    }
    for(int id = 1;id <= m;id++){
        for(int i = 0;i < p[id].v.size();i++) for(int j =i+1;j < p[id].v.size();j++){
            ll x = p[id].v[i].fi,y = p[id].v[j].fi,z = p[id].v[i].se + p[id].v[j].se;
            floyd[y][x] = floyd[x][y] = min(floyd[x][y],z);
        }
    }

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) for(int k = 1;k <= n;k++){
        if(i == j || i == k || j == k) continue;
        floyd[i][j] = min(floyd[i][j] , floyd[i][k] + floyd[k][j]);
    }


    for(int _ = 1;_ <= q;_++) solve();
    return 0;
}