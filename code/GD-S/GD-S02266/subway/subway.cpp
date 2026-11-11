#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
int z,n,m,d,q;
int w[500005];
vector<pii>a[505];
vector<pii>b[500005];
vector<pii>c[500005];
bool vis[500005],v[500005];
void dfs(int x){
	v[x]=1;
	for(auto k:b[x]){
//		if(vis[k.f])continue;
//		vis[k.f]=1;
		for(auto p:a[k.f]){
			c[x].push_back({p.f,p.s+k.s});
			c[p.f].push_back({x,p.s+k.s});
			if(v[p.f])continue;
			dfs(p.f);
		}
	}
}
int dij(int x,int y){
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	int dist[500005];
	memset(dist,0x3f3f3f3f,sizeof dist);
	q.push({0,x});
	dist[x]=0;
	while(!q.empty()){
		pii p=q.top();
		q.pop();
		vis[p.s]=1;
		if(p.s==y)return p.f;
		for(auto k:c[p.s]){
			if(dist[k.f]>dist[p.s]+k.s){
				dist[k.f]=dist[p.s]+k.s;
				if(!vis[k.f])q.push({dist[k.f],k.f});
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>z>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back({x,y});
			b[x].push_back({i,y});
		} 
	}
	for(int i=1;i<=n;i++){
		if(!v[i])dfs(i);
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<"   ";
//		for(auto k:c[i]){
//			cout<<k.f<<" "<<k.s<<" ";
//		}
//		cout<<endl;
//	}
    for(int i=1;i<=q;i++){
    	int x,y;
    	cin>>x>>y;
    	cout<<dij(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
