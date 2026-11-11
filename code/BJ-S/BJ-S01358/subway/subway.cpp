#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
long long MX=1000000000000000;
int c,n,m,d,T;
vector<pair<int,long long> > g[M];
int w[M],k[N],a[M];
long long t[M],dis[M];
bool vis[M];

void Dijkstra(int s,int e){
	priority_queue<pair<long long,int> > q;
	for(int i=1;i<=m;i++) { vis[i]=0; dis[i]=MX; }
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int cur=q.top().second;
		vis[cur]=1;
		//cout<<cur<<" "<<dis[cur]<<" "<<dis[e]<<"\n";
		if(cur==e) break;
		q.pop();
		for(int i=0;i<g[cur].size();i++){
			int x=g[cur][i].first;
			if(vis[x]==1) continue;
			long long y=g[cur][i].second;
			if(dis[x]>dis[cur]+y){
				dis[x]=dis[cur]+y;
				q.push(make_pair(-y,x));
			}
		}
	}
	cout<<dis[e]+w[s]+w[e]<<"\n";
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			for(int xxx=1;xxx<j;xxx++){
				g[a[xxx]].push_back(make_pair(a[j],t[xxx]+t[j]));
				g[a[j]].push_back(make_pair(a[xxx],t[xxx]+t[j]));
			}
		}
	}
	while(T--){
		int u,v;
		cin>>u>>v;
		Dijkstra(u,v);
	}
	return 0;
}
