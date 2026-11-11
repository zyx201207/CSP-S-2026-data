#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a;
vector<int>b;
vector<int>ans;
int n,m;

void dfs(int x) {
	if(x>n)return;
	ans[a[x]]++;
	dfs(b[a[x]]+1);
}

signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n+1);
	b.resize(m+1);
	ans.resize(m+1);
	for(int i=1; i<=n; i++)
		cin >> a[i];
	for(int i=n; i>=1; i--)
		if(!b[a[i]])
			b[a[i]] = i;
	for(int i=1; i<=n; i++)
		dfs(i);
	for(int i=1; i<=m; i++)
		cout<<ans[i]<<(i==m?"\n":" ");
	return 0;
}
