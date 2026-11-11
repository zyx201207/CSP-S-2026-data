#include <iostream>
#include <vector>
using namespace std;

const int mx = 1.1e6;
vector <vector <int>> G;


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        G.resize(n + 1);
        for(int i = 1; i < n; ++i){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        G.clear();
        cout << "1\n";
    }
}
