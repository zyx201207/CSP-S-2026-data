#include<bits/stdc++.h>
using namespace std;
int c, t;
inline void solve(){
	int n, d;
	long long x[2000001];
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &x[i]);
	long long ans = 0;
	for(int i = 2; i < n; i++)
		for(int j = 1; j <= n; j++)
			if(j + i <= n)
				ans++;
	printf("%lld\n", ans);
} 
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--)
		solve();
} 
