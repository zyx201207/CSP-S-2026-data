#include<bits/stdc++.h>
using namespace std;
int n,k,w[500005],ans=1e9;
vector<int> g[500005];
struct node{
	int u,fa,b;
};
void bfs(int st){
	queue<node> q;
	q.push({st,0,0});
	w[st]=0;
	while(!q.empty()){
		int u=q.front().u,fa=q.front().fa,b=q.front().b;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(v==fa)continue;
			w[v]=b+1;
			q.push({v,u,b+1});
		}
	}
	return;
}
void anss(int x,int y){
	bfs(x);
	int sum=0,ww[500005];
	for(int i=1;i<=n;i++)ww[i]=w[i];
	bfs(y);
	for(int i=1;i<=n;i++)sum=max(sum,min(ww[i],w[i]));
	ans=min(ans,sum);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;ans=1e9;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)anss(i,j);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
