#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m,a[N],mx,cnt,v[50],ans;
long long dp[N];
void dfs (int l,int now,int s,int last) {
	if (l==m) {
		mx = max(mx,s);
		return;
	}
	for (int i = now; i<= n;i++) {
		last = s;
		s &= a[i];
		dfs(l+1,i+1,last);
		s = (s|a[i]);
	}
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for ( int i = 1; i <= n;i++) {
		cin >> a[i];
	}
	dfs(0,1,0);
	cout << mx;
	return 0;
}
