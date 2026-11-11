#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int N = 505;
const int M = 5e5+5;
const ll INF = 1e18;
int c , n , m , d , q;
ll w[N];
pair<int,ll> p[N][5];
vector< pair<int,ll> > xi[M] , e[N+N];
bool ch[N][M];
ll dis[N+N][N+N];
void Dijkstra(int st){
	for(int i = 1;i <= m;i++) dis[st][i] = INF;
	dis[st][st] = 0;
	vector<bool> vis(m+5,0);
	priority_queue< pair<ll,int> , vector<pair<ll,int> > , greater< pair<ll,int> > > q;
	q.push( {0,st} );
	while( !q.empty() ){
		int x = q.top().sc; q.pop();
		if( vis[x] ) continue;
		vis[x] = true;
		for(auto u : e[x] ){
			int to = u.fr;
			if( !vis[to] && dis[st][to] > dis[st][x] + u.sc){
				dis[st][to] = dis[st][x] + u.sc;
				q.push( {dis[st][to] , to} ); 
			}
		}
	} 
}
void bfs(int st){
	queue<int> q;
	q.push(st);
	vector<bool> vis(m+5,0);
	vis[st] = true; 
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		for(auto x : e[u]){
			if( !vis[x.fr] ){
				vis[x.fr] = true;
				q.push( x.fr );
				dis[st][x.fr] = dis[st][x.fr] + 1; 
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	int maxx = 0;
	int kk = 0; bool flag = true;
	for(int i = 1;i <= n;i++){
		int k , a , t;
		cin >> k;
		maxx = max( maxx , k );
		for(int j = 1;j <= k;j++){
			cin >> a >> t;
			if( k <= 2 ) p[i][j] = {a,t};
			xi[a].push_back( {i,t} );
			ch[i][a] = true;
			if( kk != 0 && kk != t) flag = false;
			if( kk == 0 ) kk = t;  
		}
	}
	
	if( flag ){
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++){
				if( ch[i][j] ){
					for(auto x : xi[j] )
						if( x.fr != i ) {
							e[i].push_back( {x.fr,0} );
							e[x.fr].push_back( {i,0} );
						}
				}
			}
		for(int i = 1;i <= n;i++)
			bfs(i);
		int st , en;
		while( q-- ){
			cin >> st >> en;
			cout << dis[st][en]*2*kk + w[st] + w[en] <<"\n";
		}
		return 0;
	}else if( maxx <= 2 ){
		for(int i = 1;i <= n;i++){
			int u = p[i][1].fr , v = p[i][2].fr ;
			ll w = p[i][1].sc + p[i][2].sc;
			e[u].push_back( {v,w} ); 
			e[v].push_back( {u,w} ); 
		}
		for(int i = 1;i <= m;i++)
			Dijkstra(i);
		
		int st , en;
		while( q-- ){
			cin >> st >> en;
			cout << dis[st][en] + w[st] + w[en] <<"\n";
		}
		return 0;
	}
	if( m <= 1000 ){
		memset( dis , 0x3f , sizeof dis);
		for(int i = 1;i <= n;i++) dis[i][i] = 0;
		for(int i = 1;i <= m;i++)
			for(int j = 0;j < xi[i].size();j++)
				for(int k = j+1;k < xi[i].size();k++)
					dis[ xi[i][j].fr ][ xi[i][k].fr ] = dis[ xi[i][k].fr ][ xi[i][j].fr ] = min( xi[i][j].sc + xi[i][k].sc , dis[ xi[i][j].fr ][ xi[i][k].fr ] );
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				for(int k = 1;k <= n;k++)
					dis[i][j] = min( dis[i][j] , dis[i][k] + dis[j][k] );
	}
	
	int st , en;
	while( q-- ){
		cin >> st >> en;
		ll ans = LLONG_MAX;
		for(auto x : xi[st])
			for(auto y : xi[en]) ans = min( ans , w[st] + w[en] + x.sc + y.sc + dis[x.fr][y.fr] );
		cout << ans <<"\n";
	}
	return 0;
}

