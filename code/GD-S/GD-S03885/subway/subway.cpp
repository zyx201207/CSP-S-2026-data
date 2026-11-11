#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n,m,Q;
int w[500007];
vector<pii> v[500007];
int to[507][507],d[507][507];
priority_queue<pii,vector<pii>,greater<pii> > q; 
int vis[507];
void dji(int sx){
	d[sx][sx]=0;
	for(int i=1;i<=n;++i) vis[i]=0;
	while(!q.empty()) q.pop();
	q.push({d[sx][sx],sx});
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int nx=1;nx<=n;++nx){
			if(to[x][nx]==LONG_LONG_MAX/100) continue;
			if(d[sx][nx]>d[sx][x]+to[x][nx]){
				d[sx][nx]=d[sx][x]+to[x][nx];
				q.push({d[sx][nx],nx});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int ccc,ddd;
	cin>>ccc>>n>>m>>ddd>>Q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			to[i][j]=d[i][j]=LONG_LONG_MAX/100;
		}
	}
	for(int i=1;i<=n;++i){
		int k,x,y;
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<v[i].size();++j){
			for(int k=j+1;k<v[i].size();++k){
				int x=v[i][j].first,y=v[i][k].first,z=v[i][j].second+v[i][k].second;
				to[x][y]=min(to[x][y],z),to[y][x]=min(to[y][x],z);
			}
		}
	}
	for(int i=1;i<=n;++i) dji(i);
	for(int qq=1;qq<=Q;++qq){
		int x,y,ans=LONG_LONG_MAX;
		cin>>x>>y;
		for(int i=0;i<v[x].size();++i){
			for(int j=0;j<v[y].size();++j){
				int tx=v[x][i].first,ty=v[y][j].first;
				ans=min(ans,w[x]+w[y]+d[tx][ty]+v[x][i].second+v[y][j].second);
			}
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
