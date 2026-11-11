#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define int long long
using PI=pair<int,int>;
const int N=1010,CN=20010;
int c,m,n,d,q,dis[N][CN],cnt,vis[N][CN],a[N];
vector<PI> e[CN];
void dij(int x){
	priority_queue<PI,vector<PI>,greater<PI> > q;
	REP(i,1,cnt) dis[x][i]=1e18;
	dis[x][x]=0;q.push({0,x});
	while(!q.empty()){
		auto now=q.top();q.pop();
		if(vis[x][now.second]) continue;
		vis[x][now.second]=1;
		for(auto u:e[now.second]){
			if(dis[x][u.first]>dis[x][now.second]+u.second){
				dis[x][u.first]=dis[x][now.second]+u.second;
				if(!vis[x][u.first]) q.push({dis[x][u.first],u.first});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	REP(i,1,n) cin>>a[i];
	cnt=n;int lst;
	REP(i,1,m){
		int x;cin>>x;
		REP(j,1,x){
			int f,t;cin>>f>>t;
			e[f].push_back({++cnt,t});e[cnt].push_back({f,t});
			if(j!=1) e[cnt].push_back({lst,0}),e[lst].push_back({cnt,0});
			lst=cnt;
		}
	}
	REP(i,1,n) dij(i);
	while(q--){
		int x,y;cin>>x>>y;if(x>y) swap(x,y);
		cout<<dis[x][y]+a[x]+a[y]<<"\n";
	}
	return 0;
}
//Oct31==Dec25?
/*
#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define int long long
using PI=pair<int,int>;
const int N=510,CN=15010;
int c,m,n,d,q,dis[N][CN],cnt,vis[N][CN];
vector<PI> e[CN];
void dij(int x){
	priority_queue<PI,vector<PI>,greater<PI> > q;
	REP(i,1,cnt) dis[x][i]=1e18;
	dis[x][x]=0;q.push({0,x});
	while(!q.empty()){
		auto now=q.top();q.pop();
		if(vis[x][now.second]) continue;
		vis[x][now.second]=1;
		for(auto u:e[now.second]){
			if(dis[x][u.first]>dis[x][now.second]+u.second){
				dis[x][u.first]=dis[x][now.second]+u.second;
				if(!vis[x][u.first]) q.push({dis[x][u.first],u.first});
			}
		}
	}
}
signed main(){
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	REP(i,1,n){
		int x;cin>>x;
		e[i].push_back({i+n,x});
		e[i+n].push_back({i,x});
	}
	cnt=n*2;int lst;
	REP(i,1,m){
		int x;cin>>x;
		REP(j,1,x){
			int f,t;cin>>f>>t;
			e[f+n].push_back({++cnt,t});e[cnt].push_back({f+n,t});
			if(j!=1) e[cnt].push_back({lst,0}),e[lst].push_back({cnt,0});
			lst=cnt;
		}
	}
	REP(i,1,n) dij(i);
	while(q--){
		int x,y;cin>>x>>y;
		cout<<dis[x][y]<<"\n";
	}
	return 0;
}
//Oct31==Dec25?
*/
