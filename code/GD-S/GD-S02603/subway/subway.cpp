#include<bits/stdc++.h>

using namespace std;

using ll=long long;

using db=double;

#define int ll

#define endl '\n'

const int N = 6e5+8, inf = 0x3f3f3f3f3f3f3f3f;
int c,m,n,d,qk;
vector<array<int,2>> gid[N];
int dis[508][508],dist[2008];
int dist2[N];
struct node{
	int x,d; 
	operator <(const node& a) const{
		return a.d<d;
	}
};

void dij(int s){
	memset(dist,0x3f,sizeof(dist));
	priority_queue<node> q;
	q.push({s,0});
	dist[s]=0;
	while(!q.empty()){
		int x=q.top().x,d=q.top().d;
		q.pop();
		for(auto p:gid[x]){
			int y=p[0],dd=p[1];
			if(dist[y]>d+dd){
				dist[y]=d+dd;
				q.push({y,d+dd});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[s][i]=dist[i];
	}
}

void solve(){
	cin>>c>>m>>n>>d>>qk;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		gid[i].push_back({i+n+m,x});
		gid[i+n+m].push_back({i,x});
	}
	for(int i=1;i<=m;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int x,t; cin>>x>>t;
			gid[x+n+m].push_back({n+i,t});
			gid[n+i].push_back({x+n+m,t});
		}
		
	}
	if(m<=1000){
		for(int i=1;i<=n;i++){
			dij(i);
		}
		for(int i=1;i<=qk;i++){
			int s,t; cin>>s>>t;
			cout<<dis[s][t]<<endl;
		}
	}else if(n==2){
		priority_queue<node> q;
		q.push({1,0});
		for(int i=1;i<=n+n+m;i++){
			dist2[i]=inf;
		}
		dist2[1]=0;
		while(!q.empty()){
			int x=q.top().x,d=q.top().d;
			q.pop();
			for(auto p:gid[x]){
				int y=p[0],dd=p[1];
				if(dist2[y]>d+dd){
					dist2[y]=d+dd;
					q.push({y,d+dd});
				}
			}			
		}
		dis[1][2]=dist2[2],dis[2][1]=dist2[2];
		for(int i=1;i<=qk;i++){
			int s,t; cin>>s>>t;
			if(s>t) swap(s,t);
			cout<<dis[s][t]<<endl;
		}
	}
	
	
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	solve();
	return 0;
}




