#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c, n, m, d, Q;
const int M = 5e+5+5, N = 505;
struct node{
    int id, tim;
};
bool cmp(node u, node v){ return u.id < v.id; }

int w[M], l[M];
vector<node> info[N];
bitset<M> path[N];
int dis[N][N];

int getid(int k, int aa){
    int L = 0, R = l[k]-1, ans = 1;
    while(L <= R){
        int mid = (L+R>>1);
        if(info[k][mid].id <= aa) ans = mid, L = mid+1;
        else R = mid-1;
    }
    return ans;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> l[i];
        for(int j = 1; j <= l[i]; j++){
            int aa, tt;
            cin >> aa >> tt;
            path[i].set(aa, 1);
            info[i].push_back(node{aa, tt});
        }
        sort(info[i].begin(), info[i].end(), cmp);
    }

/*
    for(int i = 1; i <= n; i++){

        for(auto x:info[i]) cout << "(" << x.id << ',' << x.tim << ") ";
        cout <<'\n';
    }
*/

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dis[i][j] = 2e18;
    for(int i = 0; i <= n; i++) dis[i][i] = 0;
    for(int u = 1; u <= n; u++){
        for(int j = 1;j <= l[u]; j++){
            for(int v = 1; v <= n; v++){
                if(v == u) continue;
                int a, t;
                a = info[u][j].id;
                t = info[u][j].tim;
                if(path[u][a] && path[v][a]){
                    int x;
                    x = info[v][getid(v,a)].tim;
                    dis[v][u] = dis[u][v] = min(dis[u][v], x+t);
                }
            }
        }
    }
/*
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        cout << "dis("<<i <<"," << j <<") = " << dis[i][j] << '\n';
*/


    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    while(Q--){
        int x, y; cin >> x >> y;
        int tmp = w[x]+w[y], ans = 2e18;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(path[i][x] && path[j][y]){
                /*
                cout << "s=" << i <<",t=" << j <<'\n';
                cout << info[i][getid(i, x)].tim <<' '
                     << info[j][getid(j, y)].tim <<' '
                     << dis[x][y] <<'\n';
                */
                ans = min(ans, info[i][getid(i, x)].tim + info[j][getid(j, y)].tim + dis[i][j]);
            }
        cout << ans + tmp << '\n';
    }
    return 0;
}
