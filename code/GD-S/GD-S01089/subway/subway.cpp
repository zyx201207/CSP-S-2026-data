#include<bits/stdc++.h>
#define int long long
using namespace std;
using LL = long long;
const int N = 5e5,INF = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,dis[510][510],D[510];
int a[N+10];
vector< pair<int,int> > vec[N+10];
vector<int> adj[510];
void work(int u){
	priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > mq;
	for(pair<int,int> p:vec[u]){
		mq.push({a[u]+p.second,p.first});
		D[p.first]=a[u]+p.second;
	}
	while(!mq.empty()){
		pair<int,int> p=mq.top();
		mq.pop();
		int u=p.second;
		for(int v:adj[u]){
			if(D[v]>D[u]+dis[u][v]){
				D[v]=D[u]+dis[u][v];
				mq.push({D[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int p,t;
			cin>>p>>t;
			vec[p].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int num=vec[i].size();
		for(int j=0;j<num-1;j++){
			pair<int,int> u=vec[i][j];
			for(int p=j+1;p<num;p++){
				pair<int,int> v=vec[i][p];
				if(dis[u.first][v.first]==INF){
					adj[u.first].push_back(v.first);
					adj[v.first].push_back(u.first);
				}
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
				dis[v.first][u.first]=min(dis[v.first][u.first],u.second+v.second);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(D,0x3f,sizeof(D));
		work(x);
		int ans=INF;
		for(pair<int,int> p:vec[y]){
			ans=min(ans,D[p.first]+p.second+a[y]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
