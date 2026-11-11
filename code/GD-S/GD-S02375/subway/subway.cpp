#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long w[100005];
	int c, n, d, q;
	int a[1005][1005], t[1005][1005], x[100005], y[100005];
	long long m;
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> w[i];
	}
	for(int i=1; i<=n; i++){
		int k;
		cin >> k;
		for(int j=1; j<=k; j++){
			int e, f;
			cin >> e >> f;
			a[i][j] = e;
			t[i][j] = f;
		}
	}
	for(int i=1; i<=q; i++){
		cin >> x[i] >> y[i];
	}
	for(int i=1; i<=q; i++){
		if(abs(x[q]-y[q])==1){
			int ans = w[x[q]] + t[x[q]][x[q]] + t[x[q]][y[q]] + w[y[q]];
			cout << ans;
		}
	}
	return 0;
} 
