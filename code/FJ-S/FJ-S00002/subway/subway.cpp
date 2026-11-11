#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+10;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > que;
vector<pair<int,int> > e[MAXM*2];
long long dis[MAXM*2],sum[MAXM*2];
int w[MAXM];
int c,n,m,d,q,k,a,lasta,t,x,y,cnt;
void addEdge(int u,int v,int w){
	e[u].push_back(make_pair(v,w));
	return;
}
void DFS(int u,int fa){
	for(int i=0;i<(int)(e[u].size());i++){
		int v=e[u][i].first,w=e[u][i].second;
		if(v==fa){
			continue;
		}
		DFS(v,u);
		sum[u]=sum[v]+w;
	}
	return;
}
long long Dijkstra(){
	memset(dis,0x3fLL,sizeof(dis));
	dis[x]=0LL;
	que.push(make_pair(dis[x],x));
	while(!que.empty()){
		int u=que.top().second;
		long long d=que.top().first;
		que.pop();
		if(d>dis[u]){
			continue;
		}
		for(int i=0;i<(int)(e[u].size());i++){
			int v=e[u][i].first,w=e[u][i].second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				que.push(make_pair(dis[v],v));
			}
		}
	}
	return dis[y];
}
void Solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			cnt++;
			if(j>1){
				addEdge(cnt,cnt-1,0);
				addEdge(cnt-1,cnt,0);
			}
			lasta=a;
			addEdge(a,cnt,t);
			addEdge(cnt,a,t);
		}
	}
	if(d==2){
		for(int i=1;i<=cnt;i++){
			if((int)(e[i].size())==1){
				DFS(i,0);
				break;
			}
		}
		while(q--){
			cin>>x>>y;
			cout<<w[x]+llabs(sum[x]-sum[y])+w[y]<<'\n';
		}
	}else{
		while(q--){
			cin>>x>>y;
			cout<<w[x]+Dijkstra()+w[y]<<'\n';
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}