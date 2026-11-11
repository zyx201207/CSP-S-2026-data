#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll c,t,n,k,u,v,w[N+10],ans,vis[N+10],vis2[N+10],ma,b[N+10],mi=1e18;
vector<int> e[N+10];
void dfs2(int u,ll len) {
	if(b[u]) ans=min(ans,len);
	vis[u]=1;
	for(int i=0;i<e[u].size();i++) {
		int v=e[u][i];
		if(vis[v]) continue;
		dfs2(v,len+1);
	}
}
void dfs3(int u) {
	vis2[u]=1;
	for(int i=0;i<e[u].size();i++) {
		int v=e[u][i];
		if(vis2[v]) continue;
		dfs3(v);
	}
}
void dfs(ll d,ll g) {
	if(d==n+1) {
		int ss2=0;
		for(int i=1;i<=n;i++)
			vis2[i]=0;
		for(int i=1;i<=k;i++) {
			if(!vis2[w[i]]) {
				++ss2;
				if(ss2>2) break;
				dfs3(w[i]);
			}
		}
		if(ss2>2) return ;
		ma=0;
		for(int i=1;i<=n;i++) {
			if(b[i]) continue;
			ans=1e18;
			dfs2(i,0);
			for(int j=1;j<=n;j++)
				vis[j]=0;
			ma=max(ma,ans);
		}	
		mi=min(mi,ma);
		return ;
	}
	if(g<k) {
		b[d]=1;
		w[g+1]=d;
		dfs(d+1,g+1);
		b[d]=0;
	}
	dfs(d+1,g);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		ll f=0;
		for(int i=1;i<n;i++) {
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			if(u==i&&v==i+1) ;
			else f=1;
		}
		if(k<=2) cout<<1<<"\n";
		else if(f==0) cout<<n-k<<"\n";
		else {
			mi=1e18;
			dfs(1,0);
			cout<<mi<<"\n";
		}
	}
	
	
	
	return 0;
} 
