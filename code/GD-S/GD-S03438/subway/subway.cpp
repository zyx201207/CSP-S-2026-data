#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,k[520];//cyq
struct Nove{
	int to,v;
};
vector<Nove> G[1145141*5];
int dis[1145141*5],cg[1145141*5];
bool vis[1145141*5];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,x;i<=m;i++){
		cin>>x;
		G[i].push_back({i+m,x});
		G[i+m].push_back({i,x});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int last=0;
		for(int j=1;j<=k[i]*2;j++){
			int x;
			cin>>x;
			if(j%2==1){
//				G[1000000+i].push_back({x,0});
				last=x;
//				G[x].push_back({1000000+i,0});
			}else{
				G[m*2+i].push_back({last+m,x});
				G[last+m].push_back({m*2+i,x});
			}
		}
	}
	for(int j=1;j<=q;j++){
		int x,y;
		cin>>x>>y;
		vis[x]=true;
		queue<int> q;
		q.push(x);
		dis[x]=0;
		while(!q.empty()){
			int u=q.front();
//			cout<<u<<' '<<dis[u]<< endl;
			q.pop();
			vis[u]=false;
			for(int i=0;i<G[u].size();i++){
				int v=G[u][i].to,w=G[u][i].v;
				if(dis[v]>dis[u]+w||cg[v]<j){
					cg[v]=j;
					dis[v]=dis[u]+w;
					if(!vis[v]){
						vis[v]=true;
						q.push(v);
					}
				} 
			}
		}
		cout<<dis[y]<< endl;
	}
}
