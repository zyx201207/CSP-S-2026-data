#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll N = 1e6 + 10;
ll c, t, n, k;
vector<ll> edge[N];
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        cout << n - k * 2 << endl;
    }
    return 0;
}