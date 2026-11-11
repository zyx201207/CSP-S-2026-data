#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
};
long long c,n,m,d,q,wi[500010],ans=LLONG_MAX,x,y,vis[500100];
vector<node> g[500010];
void dfs(long long u,long long h){
	if(u==y){
		ans=min(ans,h);
		return;
	}
	if(h>ans) return;
	for(node j : g[u]){
		if(!vis[j.v]){
			vis[j.v]=1;
			dfs(j.v,h+j.w);
			vis[j.v]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>wi[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		long long now[10100],fa[50010],idx=0;
		while(k--){
			long long a,t;
			cin>>a>>t;
			now[idx++]=a,fa[a]=t;
		}
		for(int l=0;l<idx;l++){
			for(int r=0;r<idx;r++){
				if(l==r) continue;
				int L=now[l],R=now[r],sum=fa[L]+fa[R];
				g[L].push_back({R,sum});
				g[R].push_back({L,sum});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=LLONG_MAX;
		vis[x]=1;
		dfs(x,wi[x]+wi[y]);
		cout<<ans<<'\n';
	}
	return 0;
}
