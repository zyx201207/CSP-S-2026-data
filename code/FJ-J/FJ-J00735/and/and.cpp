#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n, m;
int a[N];
vector<int> ton(40, 0);
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	int maxn = 0;
	int maxp = 1, maxv = 0;
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		maxn = max(maxn, a[i]);
		int p = 1, v = 0;
		while (p <= a[i]){
			if (a[i] & p)
				ton[v]++;
			p *= 2;
			v++;
		}
	}
	while (maxp <= maxn){
		maxp *= 2;
		maxv++;
	}
	vector<int> now;
	for (int i = 1; i <= n; i++) now.push_back(a[i]);
	int ans = 0;
	for (int i = maxp, vi = maxv; i >= 1; i/=2, vi--){
		if (ton[vi] < m) continue;
		ans += i;
		vector<int> nex;
		for (int i = 0; i < 39; i++) ton[i] = 0;
		for (int j = 0; j < now.size(); j++){
			if (now[j] & i){
				nex.push_back(now[j]);
				int p = 1, v = 0;
				while (p <= now[j]){
					if (now[j] & p) 
						ton[v]++;
					p *= 2;
					v++;
				}
			}
		}
		now = nex;
	}
	printf("%lld", ans);
	return 0;
}
