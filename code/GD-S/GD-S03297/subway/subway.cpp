#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
vector<int> w;
vector<vector<int>> a,t,b;
map<int,bool> vis;
int l,r;
int ans;
void dfs(int x,int tm){
	if(x==r){
		ans=min(ans,tm);
		return;
	}
	if(tm>ans)
		return;
	for(int i=0;i<b[x].size();i++){
		int lx=b[x][i];
		for(int j=1;j<a[lx].size();j++){
			int xzd=a[lx][j];
			if(vis[xzd])
				continue;
			vis[xzd]=1;
			dfs(xzd,tm+t[lx][x]+t[lx][xzd]);
			vis[xzd]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	a.resize(n+1);
	t.resize(n+1);
	b.resize(m+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a[i].resize(k+1);
		t[i].resize(m+1);
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			b[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		ans=LLONG_MAX;
		cin>>l>>r;
		vis[l]=1;
		dfs(l,w[l]+w[r]);
		vis[l]=0;
		cout<<ans<<'\n';
	}
	return 0;
}
