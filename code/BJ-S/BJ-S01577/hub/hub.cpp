#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
vector<int> g[N];
int deg[N];
int c, t;
void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if (c == 1){
        if (n == k){
            cout << "0\n";
            return ;
        }
        if (n >= 4 && n <= 5 && k == 1){
            cout << "2\n";
            return ;
        }
        if (n <= 3){
            cout << "1\n";
            return ;
        }
        if (n == 4){
            cout << "1\n";
            return ;
        }
        if (n == 5 && k == 2){
            for (int i = 1;i <= n;i++){
                if (deg[i] > 2){
                    cout << "1\n";
                    return ;
                }
            }
            cout << "2\n";
            return ;
        }
        cout << "1\n";
        return ;
    }
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--){
        solve();
	}
	return 0;
}
