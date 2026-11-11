/*
	为了方便描述，一条地铁线可以在线路上瞬移到任何站台。 
	首先每个地铁线路是一个连通块，进入一条地铁线路的“站台”后这条线路上的任何站点都
	是等价的，那么可以先求出对于每条线路通过换乘走到任意一条线路的最短距离，这个可以
	先枚举站点，如果是换乘站，那么就O(\sum d^2)枚举两两的换乘，得到每条线路通过一次
	换乘到达每条线路的最短距离。
	然后再O(n^3)跑出任意两两线路相互换乘到达的最短距离。
	每次询问再用 O(d^2)枚举坐的最开始和最后的线路，加上从地铁口到站厅的时间就可以。
	 
*/

#include<bits/stdc++.h>

#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int M=5e5+10,N=500+10;
const ll inf=2e18+10;
int c,n,m,k[N],d,q,w[M];
// line.first-> a
// line.second->t+
vector<pii>line[N];
vector<pii>station[M];
ll dis[N][N];
ll min(ll x,int y){
	if(y<=x)return y;
	return x;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			line[i].push_back(mp(a,t));	
			station[a].push_back(mp(i,t));
		}
	}
	for(int i=1;i<=m;i++){
		if(station[i].size()<=1)continue;
		for(int j=0;j<station[i].size()-1;j++){
			for(int k=j+1;k<station[i].size();k++){
				int lnj=station[i][j].first,lnk=station[i][k].first;
				dis[lnj][lnk]=min(dis[lnj][lnk],station[i][j].second+station[i][k].second);
				dis[lnk][lnj]=dis[lnj][lnk];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
				dis[i][j]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x,y,lnx,lny,tx,ty;
		ll ans=inf;
		cin>>x>>y;
		for(int i=0;i<station[x].size();i++){
			for(int j=0;j<station[y].size();j++){
				ll tans=0;
				lnx=station[x][i].first,lny=station[y][j].first;
				tx=station[x][i].second,ty=station[y][j].second;
				tans=dis[lnx][lny]+tx+ty;
				ans=min(ans,tans);
			}
		}
		ans+=w[x]+w[y]; 
		cout<<ans<<endl;
	}

	return 0;
}


