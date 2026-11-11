//cin is so fast!!!
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e6;

int c, t, n;
long long d, x[MXN], ns;
int pre[MXN], nxt[MXN], deg[MXN], sum[MXN], f[MXN], g[MXN];

void solve1(){
	int i;
	for(i = 0;i < n;++i) deg[i] = f[i] = 0;
	for(i = 0;i < n;++i)
		if(i < nxt[i]) ++deg[nxt[i]];
	for(i = 0;i < n;++i)
		if(pre[i] < i && nxt[pre[i]] == i) sum[i] = deg[i] - (int)(nxt[i] == i) + sum[pre[i]];
		else sum[i] = 1 + deg[i] - (int)(nxt[i] == i);
	for(i = 0;i + 1 < n;++i){
		if(pre[i] == i) continue;
		int x = pre[i];
		if(nxt[x] != i + 1) f[i] = deg[i + 1] - (int)(nxt[i] == i + 1);
		else{
			f[i] = deg[i + 1] - (int)(nxt[i] == i + 1) - 1;
			f[i] += sum[x];
		}
	}
}

void solve2(){
	int i;
	for(i = 0;i < n;++i) deg[i] = g[i] = 0;
	for(i = 0;i < n;++i)
		if(pre[i] < i) ++deg[pre[i]];
	for(i = n - 1;i >= 0;--i)
		if(nxt[i] > i && pre[nxt[i]] == i) sum[i] = deg[i] - (int)(pre[i] == i) + sum[nxt[i]];
		else sum[i] = 1 + deg[i] - (int)(pre[i] == i);
	for(i = n - 1;i;--i){
		if(nxt[i] == i) continue;
		int x = nxt[i];
		if(pre[x] != i - 1) g[i] = deg[i - 1] - (int)(pre[i] == i - 1);
		else{
			g[i] = deg[i - 1] - (int)(pre[i] == i - 1) - 1;
			g[i] += sum[x];
		}
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int i, j;
	cin >> c;
	for(cin >> t;t;--t){
		cin >> n >> d;
		for(i = 0;i < n;++i) cin >> x[i];
		ns = 0;
		for(i = 0, j = 0;i < n;++i){
			for(;x[i] - x[j] > d;) ++j;
			pre[i] = j;
		}
		for(i = n - 1, j = n - 1;i >= 0;--i){
			for(;x[j] - x[i] > d;) --j;
			nxt[i] = j;
		}
		solve1();
		solve2();
		for(i = 0;i + 1 < n;++i) ns += (long long)f[i] * g[i + 1];
		cout << ns << '\n';
	}
	return 0; 
}
