# include <bits/stdc++.h>
using namespace std;
const int N = 505, M =5e5+5;

int w[M], k, t[N][M];
int c, n, m, d, q;
vector<int> arr[M]; // [station][line]
int dis[N][N];

inline void build() {
    for (int s = 1; s<=n; s++) {
        int sz = arr[s].size();
        for (int i=1; i<=sz; i++) {
            for (int j=i+1; j<=sz; j++) {
                dis[i][j] = dis[j][i] = min(dis[i][j], t[i][s] + t[j][s]);
            }
        }
    }
}

inline void floyd() {
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dis[i][j] = dis[j][i] = min(1ll * dis[i][j], 1ll * (dis[i][k] + dis[k][j]));
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i != j)
                dis[i][j] = INT_MAX;
        }
    }
    memset(t, 0x3f, sizeof(t));
    for (int i=1; i<=m; i++) {
        cin >> w[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> k;
        for (int j=1; j<=k; j++) {
            int a;
            cin >> a;
            cin >> t[i][a];
            arr[a].push_back(i);
            //cout << a << ' ' << t[i][a] << ' ' << arr[a].back() << ' ' << t[i][a] << '\n';
        }
        //cout << "------------------------\n";
    }
    build();
    floyd();

    for (int i=1; i<=q; i++) {
        int x, y;
        cin >> x >> y;
        long long ans = LLONG_MAX;
        int p1, p2;
        for (int l1: arr[x]) {
            for (int l2:arr[y]) {
                ans = min(ans, 1ll * dis[l1][l2] + t[l1][x] + t[l2][y]);
                if (!ans) break;
            }
        }

        cout << ans + w[x] + w[y] << '\n';
    }
}

