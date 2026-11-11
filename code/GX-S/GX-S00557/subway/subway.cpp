#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,INF=LONG_LONG_MAX-N;
int c,n,m,d,q;
int w[N],a[N],t[N];
struct node{
	int id,val;
};
vector<node> e[N];
int dis[N],vis[N];
void dijkstra(int v0){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i=1;i<=(n+1)*m;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	dis[v0]=0;
	pair<int,int> temp;
	temp.first=0,temp.second=v0;
	q.push(temp);
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].id,w=e[u][i].val;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				temp.first=dis[v],temp.second=v;
				q.push(temp);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){//xian lu
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			int u0=a[j],u1=a[j]+i*m;
			e[u0].push_back((node){u1,0});
			e[u1].push_back((node){u0,t[j]});
		}
		for(int j=1;j<=k;j++){
			int u=a[j]+i*m;
			for(int o=1;o<=k;o++){
				if(o==j) continue;
				int v=a[o]+i*m;
				e[u].push_back((node){v,t[j]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int v0,v1;
		cin>>v0>>v1;
		dijkstra(v0);
		cout<<dis[v1]+w[v0]+w[v1]<<"\n";
	}
	return 0;
}
