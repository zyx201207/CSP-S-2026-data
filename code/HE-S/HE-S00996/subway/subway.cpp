#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=500005,N=502,INF=1e18;
ll n,c,m,d,que,k;
ll a,t;
vector<pair<ll,ll> > yse[M];//线路，时间 
ll timestate[M];//车站到站厅的时间 
ll g[N][N];
ll t1,t2;
ll tempans=INF;
vector<pair<ll,ll> > e[N];
bool isvis[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
ll dis[N][N];
void dij(ll s){
	for(ll i=1;i<=n;i++) isvis[i]=0,dis[s][i]=INF;
	dis[s][s]=0;q.push({0,s});
	while(!q.empty()){
		ll idx=q.top().second,idv=q.top().first;q.pop();
		if(isvis[idx]) continue;
		isvis[idx]=1;
		for(ll i=0;i<e[idx].size();i++){
			ll idt=e[idx][i].second,idtv=e[idx][i].first;
			if(dis[s][idx]+idtv<dis[s][idt]) dis[s][idt]=dis[s][idx]+idtv,q.push({dis[s][idt],idt});
			
		}
	}
	while(!q.empty()) q.pop();
	//for(ll i=0;i<e[s].size();i++) e[s][i].first=min(e[s][i].first,dis[s][e[s][i].second]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>que;
	for(ll i=1;i<=m;i++) cin>>timestate[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(;k>0;k--){
			cin>>a>>t;
			yse[a].push_back({i,t});
		}
	}//初始图 
	for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) g[i][j]=INF;
	for(ll i=1;i<=m;i++){
		if(yse[i].size()<=1) continue;
		for(ll j=0;j<yse[i].size();j++) for(ll mm=0;mm<j;mm++){
			ll x=yse[i][j].first,valx=yse[i][j].second,y=yse[i][mm].first,valy=yse[i][mm].second;
			g[x][y]=min(g[x][y],valx+valy);
			g[y][x]=g[x][y];
			g[x][x]=0,g[y][y]=0;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			if(g[i][j]!=INF) e[i].push_back({g[i][j],j}),e[j].push_back({g[i][j],i});
		}
	}//建图 no problem!
	for(ll i=1;i<=n;i++) dij(i);
	while(que--){
		cin>>t1>>t2;
		tempans=INF;//ll tempshort=INF;
		for(ll i=0;i<yse[t1].size();i++)for(ll j=0;j<yse[t2].size();j++){
			tempans=min(tempans,dis[yse[t1][i].first][yse[t2][j].first]+yse[t1][i].second+yse[t2][j].second);
			tempans=min(tempans,dis[yse[t2][i].first][yse[t1][j].first]+yse[t1][i].second+yse[t2][j].second);
			//tempshort=min(tempshort,dis[yse[t2][i].first][yse[t1][i].first]);
		}cout<<tempans+timestate[t1]+timestate[t2]<<endl;
		
	}
	
	fclose(stdin);
	fclose(stdout);
	//correct on tow tasks!!!!! 
	return 0;
} 
