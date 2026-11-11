# include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll c, n, m, d, q;
int w[500005], k[505], a[505][500005];
int t[505][500005];
int s[100005], e[100005], r[100005];
int main(void){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%d %d", &a[i][j], &t[i][j]);
		}
	}
	for(int i = 1; i <= q; i++){
		scanf("%d %d", &s[i], &e[i]);	
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k[i]; j++){
			r[i] += t[i][j];
		}
		cout << r[i] << endl;
	}
	
	return 0;
}
