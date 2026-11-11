#include <bits/stdc++.h>
#define int long long
#define FOR(i,l,r) for(int i = l;i <= r;i++)
using namespace std;

int cnt[2000006];

int a[2000006];

int ans;
int c,t;
int n,d;

void dfs(int x,int s,int fa, int steps) {
//	cout << x << ' ' << fa << ' ' << steps <<' ' << ceil((a[x] - a[s]) *1.0 / d) << '\n';
	if (ceil((a[x] - a[s]) *1.0 / d) == steps) cnt[x]++;
	if (x >= n) return;
	FOR(i, x+1, n) {
		if (a[i] - a[x] > d) break;
		dfs(i,s, x, steps + 1);
//		cout << '\n';
	}
}

#undef int
int main () {
#define int long long

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin >> c >> t;
	
	while(t--) {
		ans = 0;
		
		cin >> n >> d;
	
		FOR(i, 1, n) cin >> a[i];
		
		FOR(i, 1, n) {
			FOR(j, 1, n) cnt[j] = 0;
			dfs(i,i,0,0);
			FOR(i, 1, n) if (cnt[i] == 2) ans++;
		}
		
		cout << ans << '\n';
	}

	return 0;
}
