#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e2 + 10, M = 5e5 + 10;

struct Node{
    //subway's id and weight of edge
    int id, w;
};

int C, n, m, D, Qnum, w[M];
ll e[N][N];
vector<Node> line[M]; 

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    
    cin >> C >> n >> m >> D >> Qnum;
    for(int i = 1; i <= m; i ++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i ++){
        int k; cin >> k;
        for(int j = 1; j <= k; j ++){
            int sta, t;
            cin >> sta >> t;
            line[sta].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            e[i][j] = INF;
            if(i == j) e[i][j] = 0;
        }
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j < (int)line[i].size(); j ++){
            int s1 = line[i][j].id, w1 = line[i][j].w;
            for(int k = j + 1; k < (int)line[i].size(); k ++){
                int s2 = line[i][k].id, w2 = line[i][k].w;
                e[s1][s2] = e[s2][s1] = min(e[s1][s2], 1ll*w1 + w2);
                // cerr << s1 << " <--> " << s2 << " = " << e[s1][s2] << "\n"; 
            }
        }
    }    
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    while(Qnum--){
        int x, y; ll ans = INF;
        cin >> x >> y;
        for(auto st1 : line[x]){
            for(auto st2 : line[y]){
                ans = min(ans, e[st1.id][st2.id] + st1.w + st2.w);
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }

    return 0;
}