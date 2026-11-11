#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f
#define lowbit(x) x&(-x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define pii pair<int,int>
using namespace std;

const int MAXN=5e2+10,MAXM=5e5+10,MAXK=2e4+10;
int w[MAXM];
int k[MAXN],a[MAXN][MAXK],t[MAXN][MAXK];
vector<int> adj[MAXM];
int c,n,m,d,q;

void build(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++)adj[a[i]].push_back(a[j]);
	}
}

int bfs(int start,int end){
	queue<int> q;
	int vis[MAXN];
	q.push(start);
	vis[start]=1;
	int ans=0;
	while(!q.empty()){
		int u=q.front();
		if(u==end)return ;
		for(int v:adj[u]){
			if(!vis[v]){
				vis[v]=1;//is visit
				q.push(v);
				ans++;
			}
		}
	}
}

void Code(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	build();
	while(q--){
		int x,y;cin>>x>>y;
		int ans=bfs(x,y);
		printf("%lld\n",ans);
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t;t=1;
	while(t--)Code();
	return 38&17;
}

