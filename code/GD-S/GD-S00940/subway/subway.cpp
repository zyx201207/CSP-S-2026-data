#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[505],x[505],f[5000050];
struct node{
	int v;
	int w;
};
vector<node> g[5000050];
int bfs(int u,int z){
	memset(f,0x3f,sizeof(f));
	queue<node> q;
	q.push({u,0});
	while(!q.empty()){
		int c=q.front().v;
		int s=q.front().w;
		q.pop();
		for(auto [v,w] : g[c]){
			if(f[v]>s+w){
				q.push({v,s+w});
				f[v]=s+w;
			}
		}
	}
	return f[z];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t;
			cin>>x[j]>>t;
			g[x[j]].push_back({x[j]+(m*i),t});
			g[x[j]+(m*i)].push_back({x[j],t});
			if(j>=2){
				g[x[j-1]+(m*i)].push_back({x[j]+(m*i),0});
				g[x[j]+(m*i)].push_back({x[j-1]+(m*i),0});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)+a[x]+a[y]<<"\n";
	}
}
