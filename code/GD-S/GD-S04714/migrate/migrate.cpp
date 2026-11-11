#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e6 + 10;
int c, t, n, d;
int a[MAX];
vector<int> g[MAX];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int vds;
		bool flag = 1;
		for (int i = 2; i <= n; i++){
			if (i == 2) vds = a[i] - a[i - 1];
			else if (a[i] - a[i - 1] != vds) flag = 0;
		}	
		if (flag){
			cout << 0 << '\n';
			continue;
		}
		for (int i = 2; i <= n; i++){
			for (int j = i - 1; j >= 1; j--){
				if (a[i] - a[j] > d) break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++){
			
		}
	} 
	return 0;
}
