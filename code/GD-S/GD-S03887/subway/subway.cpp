#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=600000;
int c,n,m,d,q;
int w[500010];//从每个地铁站的地铁口走到站厅需要的时间。
vector<pair<int,int> >Map[600000];
int dis[MAXN];
bool vis[MAXN];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//m+i第i条线路（虚点 
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			Map[m+i].push_back({a,b});
			Map[a].push_back({m+i,b});
		}
	}
	int st,ed;
	while(q--){
		
		cin>>st>>ed;
		priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >pq;
		memset(dis,0x7f7f7f7f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		pq.push({0,st});
		dis[st]=0;
		while(!pq.empty()){
			int d=pq.top().first,u=pq.top().second;
			pq.pop();
			
			if(vis[u])continue;
			vis[u]=1;
			for(int i=0;i<Map[u].size();i++){
				int to=Map[u][i].first;
				if(dis[to]>(d+Map[u][i].second)){
					dis[to]=Map[u][i].second+d;
					//cout<<dis[to]<<" "<<to<<endl;
					pq.push({dis[to],to});
				}
			}
		}
		int ans=dis[ed]+w[st]+w[ed];
		cout<<ans<<endl;
	}
	return 0;
}


