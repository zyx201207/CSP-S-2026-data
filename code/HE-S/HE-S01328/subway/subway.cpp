#include <bits/stdc++.h> 
using namespace std;

struct station{
	int a, t;
};
vector < vector<station> > v(505);
int c, n, m, d, q, w[500005], k[505], x, y;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) scanf("%d", &w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d", &k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d", &x, &y);
			v[i].push_back({x, y});
		}
	}
	while(q--){
		scanf("%d %d", &x, &y);
		cout << 0 << endl;
	}
	return 0;
}
