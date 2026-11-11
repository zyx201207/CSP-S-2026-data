//GZ-S00266 贵阳市南明区华麟 杨博麟
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=5e5+5;
vector<pair<int,int> > e[N];
int c,n,m,d,q,ans,dis[N],k,a[205][N],t[205][N],x,y,w[M];
bool vis[M],f;
void dji(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	while(q.size()) q.pop();
	for(int i=1;i<=m;i++) dis[i]=1e9,vis[i]=0;
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second,w=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.second,w=i.first;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>2) f=1;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		int len=0;
		for(int j=1;j<=k;j++){
			for(int o=j+1;o<=k;o++){
				int u=a[i][j],v=a[i][o],w=t[i][j]+t[i][o];
				//cout<<u<<' '<<v<<' '<<w;
				e[u].push_back({w,v});
				e[v].push_back({w,u});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dji(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 


