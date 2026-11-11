#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int W[5000005];
struct node{
	long long v,w;
};
vector<node> edge[500001];
bool vis[500001];
long long ans=1e18;
void dfs(int u,int e,long long step){
	if(u==e){
		ans=min(ans,step);
		return;
	}
	for(node x:edge[u]){
		long long v=x.v,w=x.w;
		if(!vis[v]){
			vis[v]=true;
			dfs(v,e,step+w);
			vis[v]=false;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			edge[i+m].push_back({a,t});
			edge[a].push_back({i+m,t}); 
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<W[x]+ans+W[y]<<endl;
	}
	return 0;
} 
