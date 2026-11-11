#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int c,n,m,d,q,k[505],w[500005];
bool vis[1000005];
int solve(int x,int y);
struct S{
	int v,w;
	bool operator>(S b)const{
		return w>b.w;
	}
};
vector<S> G[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			G[a].push_back({m+i,t});
			G[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		solve(x,y);
		cout<<solve(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
int solve(int x,int y){
	memset(vis,0,sizeof vis);
	priority_queue<S,vector<S>,greater<S> > q;
	q.push({x,0});
	while(!q.empty()){
		auto a=q.top();
		q.pop();
		int v=a.v,w=a.w;
		if(v==y) return w;
		if(vis[v]) continue;
		vis[v]=1;
		for(int i=0;i<G[v].size();i++){
			a=G[v][i];
			q.push({a.v,w+a.w});
		}
	}
	return 0;
}
// S00843
// 32pts
