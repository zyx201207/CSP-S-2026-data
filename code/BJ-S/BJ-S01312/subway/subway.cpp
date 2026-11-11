#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10;
vector<vector<pair<int, int>>> g;

void connect(int u, int v, int w) {
    g[u].push_back({v, w});
    g[v].push_back({u, w});
}

int addvertex() {
    g.push_back({});
    return g.size() - 1;
}

struct Comp_PII {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

signed main(signed argc, char* argv[]) {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    // freopen(argv[1], "r", stdin);
    // freopen(argv[2], "w", stdout);

    // memset(g, 0x3f, sizeof g);
    int c, n, m, d, q; scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    g.resize(m + 1);
    vector<int> entrance(m + 1);

    for(int i = 1; i <= m; i++) {
        int t; scanf("%lld", &t);
        entrance[i] = addvertex();
        connect(entrance[i], i, t);
    }

    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        int p = -1;
        while(k--) {
            int x, t; scanf("%lld %lld", &x, &t);
            int v = addvertex();
            connect(x, v, t);
            if(p != -1) connect(p, v, 0);
            p = v;
        }
    }

//    for(int i = 1; i < g.size(); i++) {
  //      sort(g[i].begin(), g[i].end(), [&](const pair<int, int>& x, const pair<int, int>& y) { return x.second >= y.second; });
    //}

    /*for(int i = 1; i < g.size(); i++) {
        cout << i << "  ";
        for(auto& [v, w]: g[i]) cout << v << ' ' << w << ' ';
        cout << endl;
    }*/

    // map<pair<int, int>, int> mem;

    while(q--) {
        int s, e; cin >> s >> e;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp_PII> q;

        vector<int> dist(g.size(), INT_MAX);
        dist[entrance[s]] = 0;
        q.push({entrance[s], 0});

        while(!q.empty()) {
            // auto [u, d] = q.top();
            // mem[{s, u}] = d;
            int u = q.top().first;
            int d = q.top().second;
            q.pop();

            if(u == entrance[e]) {
                cout << d << endl;
                break;
            }

            for(int i = 0; i < g[u].size(); i++) {
                int v = g[u][i].first;
                int w = g[u][i].second;
                if(d + w < dist[v]) {
                    dist[v] = d + w;
                    q.push({v, dist[v]});
                }
            }
        }
    }

    /*
    fclose(stdin);
    fclose(stderr);
    vector<string> fa, fb;
    ifstream ifa("subway1.out);

    string x;
    while(ifa >> x) { fa.push_back(x); }

    ifstream ifb(argv[2]);

    while(ifb >> x) { fb.push_back(x); }

    if(fa.size() != fb.size()) {
        cout << "\033[91mE\033[0m: different length" << endl;
        cout << "length of " << argv[1] << ": " << fa.size() << endl;
        cout << "length of " << argv[2] << ": " << fb.size() << endl;

        return 1;
    }

    int cnt = 0;
    for(int i = 0; i < fa.size(); i++) {
        if(fa[i] != fb[i]) cnt++;
    }

    if(cnt >= 10) {
        cout << "\033[91mE\033[0m: too much difference" << endl;
        cout << "difference: " << cnt << endl;
        return 1;
    }

    bool suc = false;
    for(int i = 0; i < fa.size(); i++) {
        if(fa[i] != fb[i]) {
            cout << "\033[91mE\033[0m: different data" << endl;
            cout << "data of " << argv[1] << ": ";

            for(int j = max<int>(0, i - 2); j <= min<int>(fa.size() - 1, i + 2); j++) {
                if(j == i) cout << "\033[91m[";
                cout << fa[i];
                if(j == i) cout << "]\033[0m";
                if(j != min<int>(fa.size() - 1, i + 2))cout << ", ";
            }

            cout << endl;
            cout << "data of " << argv[2] << ": ";

            for(int j = max<int>(0, i - 2); j <= min<int>(fb.size() - 1, i + 2); j++) {
                if(j == i) cout << "\033[91m[";
                cout << fb[i];
                if(j == i) cout << "]\033[0m";
                if(j != min<int>(fb.size() - 1, i + 2))cout << ", ";
            }
            suc = true;
            cout << endl;
        }
    } */
}
