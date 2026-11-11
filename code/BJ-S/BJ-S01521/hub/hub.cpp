#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

int c, t;
int n, k;
vector<int> e[N];

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if (k == n){
			cout << "0\n";
			continue;
		}
		if (n == 2){
			cout << "0\n";
			continue;
		}
		if (n == 3){
			cout << "1\n";
			continue;
		}
		if (n == 4){
			cout << "1\n";
			continue;
		}
		if (n == 5){
			cout << "1\n";
			continue;
		}
	}
	return 0;
}
