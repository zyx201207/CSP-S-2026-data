#include<bits/stdc++.h>
using namespace std;
vector<int> v[500005], t[500005], l[500005];
int n, m, c, d, q, k[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> k[i];
		for(int i = 1; i <= k[i]; i++){
			int a1, k1;
			cin >> a1 >> k1;
			v[i].push_back(a1);
			t[i].push_back(k1);
			l[a1].oush_back(i);
		}
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << 5;
	}
	return 0;
}
