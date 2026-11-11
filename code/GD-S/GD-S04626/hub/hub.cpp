#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> ve[1000001];
int c, t, n, k, u, v;
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--){
		scanf("%lld%lld", &n, &k);
		for (int i = 1; i <= n; i++){
			ve[i].clear();
		}
		for (int i = 1; i <= n; i++){
			scanf("%lld%lld", &u, &v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		printf("%lld\n", (n - k) / 4 + 1);
	}
	return 0;
}
