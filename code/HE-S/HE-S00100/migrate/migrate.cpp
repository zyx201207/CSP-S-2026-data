#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
using namespace std;

const int N=2e6+50;

int c,t,x[N],ans=0;
int head[N],nxt[N<<1],w[N<<1],to[N<<1],tot;

void add(int x,int y,int val){
	nxt[tot]=head[x];
	to[tot]=y;
	w[tot]=val;
	head[x]=tot++;
}

int d[N];
bool vis[N];
priority_queue<pr> q;

int Dijkstra(int s,int e){
	while(!q.empty()) q.pop();
	memset(d,0,sizeof d);
	memset(vis,0,sizeof vis);
	vis[s]=1;
	q.push({s,0});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		vis[x]=1;
		for(int i=head[x];~i;i=nxt[i]){
			if(d[to[i]]+w[i]<d[x]){
				d[x]=d[to[i]]+w[i];
				q.push({-d[to[i]],to[i]});
			}
		}
	}
	return d[e];
}

vector<pr> e;

void solve(){
	ans=0;
	e.clear();
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        if(i!=j&&abs(x[i]-x[j])<=d){
	        	add(i,j,abs(x[i]-x[j]));
	        	e.push_back({i,j});
			}
	for(pr p:e) if(Dijkstra(p.first,p.second)>0) ans++;
	cout<<ans<<'\n';
}

int32_t main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--) solve();
	return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 

*/
