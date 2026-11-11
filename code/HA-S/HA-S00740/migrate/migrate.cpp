#include <bits/stdc++.h>
#define ll long long 

using namespace std;
const int N = 2e6+5; 
int n, nxt[N], pre[N]; 
ll d, a[N], f[N], g[N], sf[N], sg[N]; 

void solve () {
	cin >> n >> d; 
	for (int i = 1;i <= n;i++) cin >> a[i]; 
	for (int i = 1, j = 1;i <= n;i++) {
		while (a[i]-a[j] > d) j++; 
		pre[i] = j; 
	}
	for (int i = n, j = n;i >= 1;i--) {
		while (a[j]-a[i] > d) j--; 
		nxt[i] = j; 
	}
	for (int i = 1;i <= n;i++) {
		f[i] = 1; 
		if (pre[i] < i) {
			if (nxt[pre[i]] == i) f[i] += f[pre[i]];
			if (i < n && pre[i+1] > pre[i]) f[i] += pre[i+1]-pre[i]-1; 
		}
	}
	for (int i = n;i >= 1;i--) {
		g[i] = 1;
		if (nxt[i] > i) {
			if (pre[nxt[i]] == i) g[i] += g[nxt[i]]; 
			if (i > 1 && nxt[i-1] < nxt[i]) g[i] += nxt[i]-nxt[i-1]-1;  
		}
	}
	for (int i = 1;i <= n;i++) sf[i] = sg[i] = 0; 
	for (int i = 1;i <= n;i++) {
		if (nxt[i] > i+1) {
			if (pre[nxt[i]-1] == i) sf[nxt[i]] += f[i];
			else sf[nxt[i]]++;  			
		}
		if (pre[i] < i-1) {
			if (nxt[pre[i]+1] == i) sg[pre[i]] += g[i];
			else sg[pre[i]]++; 
		} 
	}
	ll ans = 0; 
	for (int i = 1;i < n;i++) {
		ans += sf[i+1]*sg[i]; 
	}
	cout << ans << "\n"; 
}

int main () {
	freopen("migrate.in", "r", stdin); 
	freopen("migrate.out", "w", stdout); 
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 
	int cid, T; 
	cin >> cid >> T; 
	while (T--) solve(); 
	return 0; 
}
/*
only feels like nothing could be better when I'm with you, when I'm with you
dancing all night, praying we're together, it's a breakthrough, it's a breakthrough
x x xxx
o o ooo
xx x xxx
oo o ooo
x x x xxxx
o o o oooo
xx xx xxx x x
oo oo ooo o o
x x x 
o o o 
xxx x
ooo o
xxx xxx
ooo ooo
xxxxxx
oooooo
x x o o x x o o x o x o x o x o ..............
*/
