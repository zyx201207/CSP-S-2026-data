//rp++
/**
give m stations, entering each station costs w[id]
give n lines, with ...
don't wanna translate the problem qwq
a FEN CENG TU.
in each line, build 0-value edges
as for tansfering, set station_trans
let all id link to its station_trans
another
dis[x][i][j]: dot x from line-i to line-j, min cost
then for each x, do an Floyd
20 * 20 * 20 ok
ans: w[x] + dis[x][i][j] + dis[y][j][k] + w[y]
really?
32?
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<bitset>
#define rep(i, s, e) for(int i = (s); i <= (e); i++)
#define dec(i, e, s) for(int i = (e); i >= (s); i--)
inline void AC(), Init(), PreSolve(), Input(), Solve(), Answer();
const int MAXM = 5e5, MAXN = 500;
const long long INF = ~0ull >> 2;
struct Edge{
    int to;
    long long w;
};
struct Node{
    int id;
    long long dis;
    bool operator<(const Node rhs) const;
};
int n, m, d, q;
int k[MAXN + 5];
long long w[MAXM + 5];
long long dis[MAXN + 1][MAXN + 1];
long long dist[MAXM + MAXN + 5];
std::vector<Edge> edge[MAXN + MAXM + 5];
std::priority_queue<Node> prq;
std::bitset<MAXN + MAXM + 5> vis;
inline void Dijk(int st);
signed main(){
    AC();
    return 0;
}
inline void AC(){
    Init();
    int Tcase = 1, c;
    // std::cin >> Tcase;
    std::cin >> c;
    while(Tcase--){
        PreSolve();
        Input();
        Solve();
        Answer();
    }
}
inline void Init(){
    freopen("subway.in" , "r", stdin );
    freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
}
inline void PreSolve(){}
inline void Input(){
    std::cin >> n >> m >> d >> q;
    rep(i, 1, m) std::cin >> w[i];
    int a, t;
    rep(i, 1, n){
        std::cin >> k[i];
        rep(j, 1, k[i]){
            std::cin >> a >> t;
            edge[m + i].push_back({a, t});
            edge[a].push_back({m + i, t});
        }
    }
}
inline void Solve(){
    rep(i, 1, m){
        Dijk(i);
        rep(j, 1, m) dis[i][j] = dist[j];
    }
}
inline void Answer(){
    int x, y;
    while(q--){
        std::cin >> x >> y;
        std::cout << (w[x] + w[y] + dis[x][y]) << "\n";
    }
}
inline void Dijk(int st){
    rep(i, 1, m + n) dist[i] = INF;
    vis.reset();
    dist[st] = 0, prq.push({st, 0});
    while(!prq.empty()){
        int x = prq.top().id; prq.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(Edge e: edge[x]){
            int y = e.to; long long w = e.w;
            if(dist[y] > dist[x] + w){
                dist[y] = dist[x] + w, prq.push({y, dist[y]});
            }
        }
    }
}
bool Node::operator<(const Node rhs) const{
    return dis > rhs.dis;
}
/*
* the subway looks just like a subway......
* which fills you with determination.
* SAVED

* you cannot save the world...
* ...
* but you can SAVE it.


START FISHING kai shi diao yu

freeopen "subway.in","w" //freopen "subway1.in"
cin<< cout>>
while(1)
let me think...
I LOVE CCF
I LOVE kkksc03
I LOVE YOU WHO SEE THIS FILE
RP++
WHILE(1) RP++;

if you see this, congratulations for you've been congratulated by me
i'm still _LogicFish_ (_LogicFish_qwq in Luogu) but this time i grow up
this time i will not print some strange solutions
but i wrote A LOT OF zhu-shi in each files
i like fish and look DOESN'T like a fish so don't confuse me by any other fish-like beings or non-beings tkx.
i like Phigros Milthm UNDERTALE and Neuro-Sama and other things i can't remember now
if we have any interest in common, we may be friends!
*/
/*
NOW I'M ANGRY CUZ LAST 3 PROBLEMS ARE ALL GRAPHOLOGIC (SPELLING MIGHT BE WRONG)
WHY!!!!!!!!!!!!!!
I AM VERY ANGRY BUCAUSE I JUST REVIEWED STRING-RELATED ALGORITHM AND DP YESTERDAY
WHY TREAT ME LIKE THIS CCF ...... TAT
anyway RP++ anyway i love CCF and i will keep giving CCF money so please let me get into provincal team plz...!!!
*/