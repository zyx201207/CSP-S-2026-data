//GZ-S00413 黔南州布依族苗族自治州都匀第一中学 邹佳航
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 5005;

int c,t,n;
ll d;

struct Node{
    int u,w;
};

ll vis[MAXN];
ll x[MAXN];
ll cnt[MAXN][MAXN];
queue<Node> qe;

void init(){
    for(int i = 1;i<=n;i++){
        vis[i] = 1e18;
    }
}

void bfs(){
    while(!qe.empty()){
        int u = qe.front().u;
        int w = qe.front().w;
        cnt[u][w]++;
        qe.pop();
        for(int i = u+1;i<=n;i++){
            if(x[i] - x[u] > d) break;
            vis[i] = w + 1;
            qe.push({i,w+1});
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        int ans = 0;
        cin >> n >> d;
        for(int i = 1;i<=n;i++){
            cin >> x[i];
        }
        for(int i = 1;i<=n;i++){
            qe.push({i,0});
        }
        bfs();
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(cnt[i][j] == 2){
                    ans++;
                    break;
                }
            }
        }
        cout << ans / 2 << "\n";
    }
    return 0;
}
