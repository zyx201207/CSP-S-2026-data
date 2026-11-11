#include<bits/stdc++.h>
using namespace std;
long long x[2000053];
long long cnt=0,d=0;
pair<long long,int> dis[2030053];int fa[20353],deg[2030053];//
long long w[2030053],vis[2030053];
vector<pair<int,long long> > v[53053];
void dij(int s,int qq){
	memset(fa,0,sizeof(fa));
	priority_queue<pair<long long,int> > pq;
	fa[s]=100;
	dis[s]={0,qq};
	pq.push({0,s});
	while(!pq.empty()){
		auto qt=pq.top();
		pq.pop();
		int u=qt.second;
		if(deg[u]>0)continue;
		if(vis[u]==qq)continue;
		vis[u]=qq;
		for(auto e:v[u]){
			int dj=e.second,to=e.first;
			deg[to]--;
			if(dis[to].second!=qq||dis[to].first>dis[u].first+dj){
				
				dis[to].second=qq;
				dis[to].first=dis[u].first+dj;
				fa[to]=fa[u];
				//pq.push({-dis[to].first,to});
			}else if(dis[to].second==qq&&dis[to].first==dis[u].first+dj){///
				if(fa[to]==100&&fa[u]==100){
					fa[to]=200;
				}else{
					fa[to]=300;
				}
			}
			if(fa[to]<=200&&deg[to]==0){
				if(fa[to]==200)cnt++;
				pq.push({-dis[to].first,to});
			}
		}
	}
	return;
}
void solve(int tt){
	cnt=0;
	int n;
	cin>>n>>d;
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				v[i].push_back({j,1});
				deg[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i,i+5000*tt);
	}
	cout<<cnt<<"\n";
	return;
}

int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		solve(i);
	}
	return 0;
} 
