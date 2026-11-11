# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6+5, INF = 0x3f3f3f3f;

int c, t, n;
LL d;
vector<int> G[N];
vector<LL> x;

void build() {
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n && x[j]-x[i] <= d; j++) {
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
}

int bfs(int s) {
    //cout << "e\n";
    int cnt[N], dis[N];

    bool vis[N];
    queue<int> q;

    memset(cnt, 0, sizeof(cnt));
    memset(dis, 0x3f, sizeof(dis));
    int ans = 0;
    dis[s] = 0;


    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: G[u]) {
            if (dis[u] + 1 == dis[v])
                cnt[v]++;
            else if (dis[v] + 1 < dis[u]){
                dis[v] = dis[u] + 1;
                cnt[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i=s; i<=n; i++) {
        if (cnt[i] == 2)
            ans++;
    }

    return ans;
}

int main() {

    freopen("migrate.in", "r", stdin);

    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    cin >> c >> t;
    while (t--) {

        cin >> n >> d;
        x.resize(n+5);
        for (int i=1; i<=n; i++) {
            cin >>x[i];
        }

        build();

        int ans = 0;
        for (int i=1; i<=n; i++) {

            int temp = bfs(i);
            ans += temp;
        }

        cout << ans << '\n';
        for (int i=1; i<=n; i++) {
            G[i].clear();
        }
    }
}
