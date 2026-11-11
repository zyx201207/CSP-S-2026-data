#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#ifdef DEBUG
#define dbg(x) cout << "\033[33m" x << "\033[0m"
#else
#define dbg(x)
#endif

using ll = long long;
struct Upd {
    int i, j, l;
    friend bool operator<(Upd a, Upd b) {
        return a.l<b.l;
    }
}
const int INF = 1e9;
int dist[2000005][2000005];
int dist2[2000005][2000005];

int main() {
    #ifndef DEBUG
        if(
            nullptr == freopen("migrate.in" , "r", stdin ) ||
            nullptr == freopen("migrate.out", "w", stdout)
        ) { return 1; }
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    int c, t;
    cin >> c >> t;

    for(int i=0; i<t; i++) {
        ll n, d;
        cin >> n >> d;
        ll a[2000005];
        for(int j=0; j<n; j++) {
            cin >> a[j];
        }
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                dist[j][k] = INF;
                dist2[j][k] = INF;
            }
            dist[j][j] = 0;
            dist2[j][j] = 0;
        }
        priority_queue<Upd> q;
        vector<int> g[2000005], h[2000005];
        for(int j=0; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(a[k]-a[j]<=d) {
                    g[j].push_back(k);
                    h[k].push_back(j);
                    q.push({j,k,1});
                }
            }
        }
        while(!q.empty()) {
            auto &u = q.top(); q.pop();
            int i=u.i, j=u.j, l=u.l;
            if(l >= dist2[i][j]) continue;
            if(l < dist[i][j]) {
                dist2[i][j] = dist2[j][i] = l;
            } else {
            dist[i][j] = dist[j][i] = l;}
            for(int k: g[j]) {
                q.push({i,k,l+1});
                q.push({i,k,l+dist2[j][k]});
            }
            for(int k: h[i]) {
                q.push({k,j,l+1});
                q.push({k,j,l+dist2[i][k]});
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(dist[i][j] == dist2[i][j]) cnt++;
            }
        }
        coutt << cnt << "\n";
    }

    #ifndef DEBUG
        cout << flush;
        fclose(stdin);
        fclose(stdout);
    #endif
    return 0;
}