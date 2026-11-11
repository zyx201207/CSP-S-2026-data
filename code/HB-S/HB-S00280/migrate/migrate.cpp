//rp++
/*
40?
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<bitset>
#define rep(i, s, e) for(int i = (s); i <= (e); i++)
#define dec(i, e, s) for(int i = (e); i >= (s); i--)
inline void AC(), Init(), PreSolve(), Input(), Solve(), Answer();
const int MAXN = 5000, INF = ~0u >> 2;
struct Node{
    int id, dis;
    bool operator<(const Node rhs) const;
};
int n;
long long ans;
long long d, a[MAXN + 5];
int dis[MAXN + 5], cnt[MAXN + 5];
std::vector<int> edge[MAXN + 5];
std::bitset<MAXN + 5> vis;
std::priority_queue<Node> prq;
inline void Dijk(int st);
signed main(){
    AC();
    return 0;
}
inline void AC(){
    Init();
    int Tcase = 1, c;
    std::cin >> c >> Tcase;
    while(Tcase--){
        Input();
        PreSolve();
        Solve();
        Answer();
    }
}
inline void Init(){
    freopen("migrate.in" , "r", stdin );
    freopen("migrate.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
}
inline void PreSolve(){
    ans = 0;
    rep(i, 1, n) edge[i].clear();
}
inline void Input(){
    std::cin >> n >> d;
    rep(i, 1, n) std::cin >> a[i];
}
inline void Solve(){
    if(n <= MAXN){
        rep(i, 1, n){
            rep(j, i + 1, n){
                if(a[j] - a[i] <= d) edge[i].push_back(j), edge[j].push_back(i);
            }
        }
        rep(i, 1, n){
            Dijk(i);
            rep(j, i + 1, n) if(cnt[j] == 2) ans++;
        }
    }else{
        ans = 1ll * (n) * (n - 1) / 2;
    }
}
inline void Answer(){
    std::cout << ans << "\n";
}
inline void Dijk(int st){
    rep(i, 1, n) dis[i] = INF, cnt[i] = 0;
    vis.reset();
    dis[st] = 0, prq.push({st, 0}), cnt[st] = 1;
    while(!prq.empty()){
        int x = prq.top().id; prq.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int y: edge[x]){
            if(dis[y] > dis[x] + 1){
                dis[y] = dis[x] + 1, cnt[y] = cnt[x], prq.push({y, dis[y]});
            }else if(dis[y] == dis[x] + 1) cnt[y]++;
        }
    }
}
bool Node::operator<(const Node rhs) const{
    return dis > rhs.dis;
}
/*
my english is NOT good yet
if there's anything i spell wrongly, just forgive me :)

Backward, go backward, go back to the realm, then go back to the -
(is this right?)

About the Universe
Implexrough
Evanscent
Entrance to the Chaos
M....what? Camellia i'm sorry but what's this stuff spell plz?
True Home, True World
....then what
i can't remember...
A... i can't spell it either
P... well...
HATE
De... ~~DeepSeek~~ Signals
Message
What do you want more than a happy ending?
- END -
Leave All Behind
*/