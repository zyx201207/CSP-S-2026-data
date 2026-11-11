#include<bits/stdc++.h>
using namespace std;
#define ll long long//unsigned
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define pi pair<ll,pair<ll,ll>>
const ll N=1e4+4,INF=1e9;

struct nd{
	pair<ll,ll>to;
	ll w;
};
ll c,n,m,d,Q,w[N],dt[N][505],vis[505][N];
vector<nd>e[N]; 
vector<nd>l2[502][N];
priority_queue<pi,vector<pi>,greater<pi> >q;

void check(ll x,ll y){
	
	memset(dt,0x3f,sizeof(dt));
	memset(vis,0,sizeof(vis));
	ll ans=w[x]+w[y];
	dt[x][0]=0;
	
	q.push({0,{x,0}});
	while(!q.empty()){
		ll d=q.top().second.first,h=q.top().second.second;

		q.pop();if(vis[d][h])continue;
		vis[d][h]=1;
		if(d<=m){//如果在站厅 
		if(vis[d][0])continue;
		vis[d][0]=1;
		for(nd i:e[d]){
			if(dt[i.to.first][i.to.second]>dt[d][h]+i.w){
				dt[i.to.first][i.to.second]=dt[d][h]+i.w;
				q.push({dt[i.to.first][i.to.second],{i.to.first,i.to.second}});
			}
		}
		
		
		}else{
		
		for(nd i:l2[h][d]){
			if(dt[i.to.first][i.to.second]>dt[d][h]+i.w){
				dt[i.to.first][i.to.second]=dt[d][h]+i.w;
				q.push({dt[i.to.first][i.to.second],{i.to.first,i.to.second}});
			}
		}
		
		}
	} 
	cout<<dt[y][0]+ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	fo(i,1,m){
		cin>>w[i];//站口到站厅 
	}
	fo(j,1,n){
		ll k,la;cin>>k;
		fo(i,1,k){
			ll lto,lw;
			cin>>lto>>lw;
			//站厅与站台：
			e[lto].push_back({{lto+m,j},lw});
			e[lto+m].push_back({{lto,0},lw});
			//站台与站台 
			if(i!=1){
				l2[j][lto+m].push_back({{la,j},0});
				l2[j][la].push_back({{lto+m,j},0});
			}
			la=lto+m;
		}
	}
	
	
	while(Q--){
		//相当于x站厅到y站厅的距离 
		ll x,y;
		cin>>x>>y;
		check(x,y);
	}
	
} 
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
