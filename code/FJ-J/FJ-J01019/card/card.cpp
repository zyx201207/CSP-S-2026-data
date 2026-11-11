#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;
int n,m,a[N],cnt[M],sum[M];
bitset<M> vis;vector<int> kid[M];
void dfs(int x) {
	sum[x]=cnt[x];
	for(int k:kid[x]) {
		dfs(k);sum[x]+=sum[k];
	}
}
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	for(int i=n;i>=1;i--) {
		if(vis[a[i]]) continue;
		vis[a[i]]=1;
		if(i!=n) kid[a[i+1]].push_back(a[i]);
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
}
