//GZ-S00045 王子晨 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pri priority
#define vec vector
#define fir first
#define sec second

#define rep(i,low,up) for(int i=low;i<=up;i++)
#define per(i,up,low) for(int i=low;i<=up;i++)

/*
thinking:
二分图?
最短路，3层节点：站口（单独算）、站厅、站台 
地铁不耗时，

基础时间：W起点+W终点 

running:
建立连接：站厅--t_ij--站台--t_jk--站厅 
spfa全源最短路应对q轮查询 

*/
const int N=500+3;
const int M=5e5+3;
const ll MAN=1e18;

int n,m,d,q; 
vec<int> w(M),k(N);
vec<pll> sta[21],sub[M],mp[N];
vec< vec<ll> > dir(N,vec<ll>(N,MAN));

int i,j;

void dfs(){
	
}
void dij(ll st){
	dir[st][st]=0;
	deque<ll> pq;
	vec<bool> vis(N,false);
	
	pq.push_back(st);
	while(!pq.empty()){
		int a=pq.front();
		rep(i,0,k[a]-1){
			pll next=mp[a][i];
			pq.push_back(next.fir);
			dir[st][next.fir]=min(dir[st][a]+next.sec,dir[st][next.fir]);
		}
		pq.pop_front();
	}
}

void solve(){
	cin>>n>>m>>d>>q;
	
	rep(i,1,m){
		cin>>w[i];
	}
	
	rep(i,1,n){
		cin>>k[i];
		rep(j,1,k[i]){
			int a,t;
			cin>>a>>t;
			sub[i].push_back({a,t});
			sta[a].push_back({i,t});
		}
	}
	
	rep(i,1,m){
		rep(j,0,sta[i].size()-1){
			pll p=sta[i][j];
			rep(k,0,sub[p.fir].size()-1){
				pll q=sub[p.fir][k];
				mp[i].push_back({q.fir,p.sec+q.sec});
			}
		}
	}
	rep(i,1,m){
		
	}
	
	return;
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	t=1;
	while(t--){
		
		solve();
	}
	return 0;
}
