#include<bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
ll c,n,m,d,q,w[500010],a[510][1010],t[510][1010],k[510],ans,x,y,px,py;
vector<int>g[500010];
void dfs(ll p,ll ct){
	if(p==y){
		ans=min(ans,ct);
		return;
	}
	for(ll u:g[p]){
		cout <<p<<" "<<u<<" "<<t[p][p]<<" "<<t[p][u]<<"\n";
		dfs(u,ct+t[p][p]+t[p][u]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			if(i!=a[i][j]){
				g[i].push_back(a[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>px>>py;
		x=min(px,py);
		y=max(px,py);
		ans=inf;
		dfs(x,0);
		ans+=w[x]+w[y];
		cout <<ans<<"\n";
	}
	return 0;
}
