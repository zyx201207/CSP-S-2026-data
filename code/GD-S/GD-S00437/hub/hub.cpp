#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t;
int n,k;
int u,v;
vector<int> r[1000006];
int ans;
int mi[1000005];
int xb[15];
int tot;
void dfs(int u,int fa){
	if(xb[u]) mi[u]=0,tot+=(!xb[fa]);
	if(tot>2) return;
	for(int i=0;i<r[u].size();i++) if(r[u][i]!=fa){
		mi[r[u][i]]=min(mi[r[u][i]],mi[u]+1);
		dfs(r[u][i],u);
		mi[u]=min(mi[u],mi[r[u][i]]+1);
	}
}
void sr(int k,int sy){
	if(n-k+1<sy) return;
	if(k>n){
		tot=0;
		for(int i=1;i<=n;i++) mi[i]=n-1;
		dfs(1,0);
		if(tot>2) return;
		dfs(1,0);
		int ma=0;
		for(int i=1;i<=n;i++) ma=max(ma,mi[i]);
		ans=min(ans,ma);
//		if(ma==0) for(int i=1;i)
		return;
	}
	if(sy){
		xb[k]=1;
		sr(k+1,sy-1);
	}
	xb[k]=0;
	sr(k+1,sy);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) r[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			r[u].push_back(v);
			r[v].push_back(u);
		}
		ans=n-1;
		if(n<=10){
			sr(1,k);
			cout<<ans<<"\n";
		}
	}
	return 0;
}

