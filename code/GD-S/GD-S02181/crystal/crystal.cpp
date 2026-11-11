#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL const MAXN = 1e6 + 10;

LL n, m, ans = 0;
LL a[MAXN];
LL k[MAXN];


int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	
	LL ss = 0, tt = 0;
	LL sm = 0;
	while(tt <= n){
		sm += a[++tt];
		while((tt * a[tt] - sm) > m){
			sm -= a[++ss];
		}
		ans = max(ans, tt - ss);
	}
	//ss+1
	
	cout << ans << '\n';
	
	return 0;
} 

