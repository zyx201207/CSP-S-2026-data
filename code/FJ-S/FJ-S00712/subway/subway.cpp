#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qqq,k[505];
long long w[500005],dis[505][505];
vector<int>a[505];
vector<long long>t[505];
vector<pair<int,int> >id[500005];
struct xianlu{
	int x;
	long long dis;
};
bool operator<(xianlu a,xianlu b){
	return a.dis>b.dis;
}
priority_queue<xianlu>q;
bool vis[505];
void bfs(int now){
	for(int i=1;i<=n;++i)dis[now][i]=1e18,vis[i]=false;
	dis[now][now]=0,q.emplace(xianlu{now,0});
	while(!q.empty()){
		xianlu p=q.top();
		q.pop();
		if(vis[p.x])continue;
		vis[p.x]=true;
		for(int i=1;i<=k[p.x];++i)for(auto j:id[a[p.x][i]]){
			if(vis[j.first])continue;
			if(dis[now][j.first]>dis[now][p.x]+t[p.x][i]+t[j.first][j.second]){
				dis[now][j.first]=dis[now][p.x]+t[p.x][i]+t[j.first][j.second];
				q.emplace(xianlu{j.first,dis[now][j.first]});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>qqq;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i],a[i].emplace_back(0),t[i].emplace_back(0);
		for(int j=1;j<=k[i];++j){
			int aaa;
			long long ttt;
			cin>>aaa>>ttt,a[i].emplace_back(aaa),t[i].emplace_back(ttt);
			id[aaa].emplace_back(i,j);
		}
	}
	for(int i=1;i<=n;++i)bfs(i);
	while(qqq--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto u:id[x])for(auto v:id[y]){
			if(u.first==v.first)ans=min(ans,w[x]+w[y]+t[u.first][u.second]+t[v.first][v.second]);
			else{
				ans=min(ans,w[x]+w[y]+t[u.first][u.second]+t[v.first][v.second]+dis[u.first][v.first]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
