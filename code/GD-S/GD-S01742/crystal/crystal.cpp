#include<bits/stdc++.h>
using namespace std;

int n;
long long m, a[500001], s[500001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = 1;
	for(int i = 1; i <= n; i++){
		int L = 0, R = i;
		while(L + 1 < R){
			int M = (L + R) / 2;
			if((i - M) * a[i] - s[i - 1] + s[M - 1] <= m)
				R = M;
			else
				L = M;
		}
		ans = max(ans, i - R + 1);
	}
	printf("%d\n", ans);
	return 0;
} 
