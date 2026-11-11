#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=5e5+5,M=505;
const long long INF=1e18;
int c,n,m,d,Q,k,w[N];
long long ans,dis[M][M];
bool vis[M];
vector<pair<int,long long> > t[N],g[M];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
void dij(long long d[N],int st){
	for(int i=1;i<=n;i++)d[i]=INF,vis[i]=false;
	d[st]=0;q.push(make_pair(0,st));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=true;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i].first;
			long long W=g[x][i].second;
			if(d[y]>d[x]+W){
				d[y]=d[x]+W;
				q.push(make_pair(d[y],y));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			t[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<t[i].size();j++)
			for(int k=j+1;k<t[i].size();k++){
				pair<int,long long> x=t[i][j],y=t[i][k];
				long long W=x.second+y.second;
				g[x.first].push_back(make_pair(y.first,W));
				g[y.first].push_back(make_pair(x.first,W));
			}
	for(int i=1;i<=n;i++)dij(dis[i],i);
	while(Q--){
		int x,y;ans=INF;
		cin>>x>>y;
		for(int i=0;i<t[x].size();i++)
			for(int j=0;j<t[y].size();j++){
				int X=t[x][i].first,Y=t[y][j].first;
				long long W=t[x][i].second+t[y][j].second;
				ans=min(ans,dis[X][Y]+W+w[x]+w[y]);
			}
		cout<<ans<<"\n";
	}
	return 0;
}
