#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct stu{
	int ai;
	int ti;
};
struct tsu{
	int dd;
	int dn;
	bool operator<(tsu e)const{
		return dn>e.dn;
	}
};
vector<stu>g[505];
vector<stu>f[500005];
long long dis[500005];
bool vis[500005];
int n,m,q,w[500005];
short c,d; 
long long ans;
int bfs(int s,int e){
	priority_queue<tsu>p;
	p.push(tsu{s,0});
	for(int i=1;i<=m;i++){
		dis[i]=2100000000;
	}
	dis[s]=0;
	while(!p.empty()){
		int u=p.top().dd;
		p.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<f[u].size();i++){
			for(auto j:g[f[u][i].ai]){
				int v=j.ai,w=j.ti+f[u][i].ti;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					p.push(tsu{v,dis[v]});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	return dis[e];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			f[a].push_back(stu{i,t});
			g[i].push_back(stu{a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		ans+=bfs(x,y);
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}

