#include <bits/stdc++.h>

using namespace std;

long long c, n, m, d, q, k, u, v, t;
vector <long long> a(6660);
vector <vector <pair <long long, long long> > > b(6660, vector <pair <long long, long long> > ());
vector <vector <long long> > go(6660, vector <long long> (6660, -1));

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        cin >> k;

        for (int j = 0; j < k; j++){
            cin >> v >> t;
            b[m + i].push_back({t, v});
            b[v].push_back({t, m + i});
        }
    }

    for (int i = 0; i < m; i++){
        queue <long long> p;
        go[i][i] = 0;
        p.push(i);

        while (p.size()){
            int from = p.front();
            p.pop();

            for (int to = 0; to < b[from].size(); to++){
                if (go[i][b[from][to].second] == -1 || go[i][b[from][to].second] > go[i][from] + b[from][to].first){
                    go[i][b[from][to].second] = go[i][from] + b[from][to].first;
                    p.push(b[from][to].second);
                }
            }
        }
    }

    for (int i = 0; i < q; i++){
        cin >> u >> v;
        cout << go[u][v] + a[u] + a[v] << "\n";
    }

    return 0;
}
