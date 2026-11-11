#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, ans, a[N], x[35];
vector<int> G[35];
bool cmp(int a, int b){
	return a > b;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	x[0] = 1;
	for (int i = 1; i <= 31; i++){
		x[i] = x[i - 1] * 2;
	}
	scanf("%lld", &n);
	scanf("%lld", &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		int b = a[i];
		for (int j = 30; j >= 1; j--){
			if (b >= x[j]){
				b -= x[j];
				G[j].push_back(i);
			}
		}
	}
	for (int i = 30; i >= 1; i--){
		if (G[i].size() >= m){
			ans = x[i + 1] - 1;
			for (int v : G[i]){
				if (!m) break;
				m--;
				ans &= a[v];
			}
			break;
		}
	}
	printf("%lld", ans);
	return 0;
}
