#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 1e4;

int c, n, m, d, q;
int fix[N]; // w

int head[N], to[N], nxt[N], w[N], tot = 1;
void add(int u, int v, int tw) {
	//cout << "add_edge(" << u << ", " << v << ", " << tw << ");\n";
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    w[tot] = tw;
    //cout << "nxt[" << tot << "] = " << nxt[tot] << ", head[" << u << "] = " << tot << ", to[" << tot << "] = " << v << ", w[" << tot << "] = " << tw << "\n";
	
    nxt[++tot] = head[v];
    head[v] = tot;
    to[tot] = u;
    w[tot] = tw;
    //cout << "nxt[" << tot << "] = " << nxt[tot] << ", head[" << v << "] = " << tot << ", to[" << tot << "] = " << v << ", w[" << tot << "] = " << tw << "\n";
}

ll dist[N];
bool inq[N];
ll dijkstra(int s, int t) {
    memset(dist, 0x7f, sizeof(ll) * (m + n + 5));
    memset(inq, false, sizeof(bool) * (m + n + 5));
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    inq[s] =  true;
    while (!q.empty()) {
        int u = q.front();
        //cout << u << " => ";
        q.pop();
        inq[u] = false;
        for (int id = head[u]; id; id = nxt[id]) {
            int v = to[id];
            ll newdist = dist[u] + w[id];
            if(newdist < dist[v]) {
                dist[v] = newdist;
                q.push(v);
                inq[v] = true;
            	//cout << v << "(" << newdist << "), ";
            }
        }
        //cout << '\n';
    }
    return dist[t] + fix[s] + fix[t];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> fix[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int tto, tw;
            cin >> tto >> tw;
            add(m + i, tto, tw);
        }
    }
    for (int i = 1; i <= q; ++i) {
        int s, t;
        cin >> s >> t;
        cout << dijkstra(s, t) << '\n';
    }

    return 0;
}

    /*
    * n <= 500
    * m <= sigma(k) <= 5e5
    * d <= 20
    * q <= 1e5
    * w <= 1e9
    * k <= m
    * a <= m
    * t <= 1e9
    * a_i diff
    * edges crossing subway v <= d
    * graph connected
    */

// AC
// RP++
