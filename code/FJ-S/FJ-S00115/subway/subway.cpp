#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
using numtype = int;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    numtype c, n, m, d, Q;
    cin >> c >> n >> m >> d >> Q;

    vector<numtype> W(m, 0);
    for (numtype j = 0; j < m; ++j) cin >> W[j];

    vector<vector<numtype>> ways(n);
    vector<unordered_map<numtype, numtype>> dist(m);

    for (numtype i = 0; i < n; ++i){
        numtype k;
        cin >> k;
        ways[i].reserve(k);

        for (numtype j = 0; j < k; ++j){
            numtype a, t;
            cin >> a >> t;
            --a;

            ways[i].emplace_back(a);
            dist[a].emplace(i, t);
        }
    }

    vector<bool> found(m, false);

    for (numtype q = 0; q < Q; ++q){
        fill(found.begin(), found.end(), false);

        numtype x, y;
        cin >> x >> y;
        --x;--y;

        priority_queue<pair<numtype, numtype>, deque<pair<numtype, numtype>>,
            greater<pair<numtype, numtype>>> pq;
        pq.emplace(0, x);

        while (!pq.empty()){
            pair<numtype, numtype> got = pq.top();
            pq.pop();
            numtype top = got.second;

            if (found[top]) continue;
            found[top] = true;

            if (top == y){
                cout << (got.first + W[x] + W[y]) << "\n";
                break;
            }

            for (auto p : dist[top]){
                numtype price = got.first + p.second;

                for (numtype i : ways[p.first]){
                    if (i == top || found[i]) continue;
                    pq.emplace(price + dist[i][p.first], i);
                }
            }
        }
    }

    return 0;
}
