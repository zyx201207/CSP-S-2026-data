#include <bits/stdc++.h>
using namespace std;
#define int long long

int read() {
	int aa = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch=='-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		aa = (aa<<3) + (aa<<1) + (ch^48);
		ch = getchar();
	}
	return aa*f;
}
const int N = 2e6+10;
int n, d;
int x[N];
int vis[N];
void solveA() {
	int ans = 0;
	n = read(), d = read();
	for(int i = 1;i<=n;i++)
		x[i] = read();
	int dd = x[2]-x[1];
	if(dd >= d || x[n]-x[1] < d) {
		cout<<"0\n";
		return;
	}
	int step = d/dd+1;
	ans = n-(step+step-2)+1;
	cout<<ans<<"\n";
}
void dfs(int pos) {
	vis[pos]++;
	for(int i = pos+1;i<=n;i++) {
		if(x[i]-x[pos] <= d)
			dfs(i);
		else
			break;
	}
}
void solve() {
	int ans = 0;
	n = read(), d = read();
	memset(vis, 0, sizeof vis);
	for(int i = 1;i<=n;i++)
		x[i] = read();
	dfs(1);
	for(int i = 1;i<=n;i++)
		if(vis[i]==2)
			ans++;
	cout<<ans<<"\n";
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C_C = read(), T_T = read();
	while(T_T--) {
		solveA();
	}
	return 0;
}
