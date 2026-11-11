#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,maxm=5e5+5;
const int inf=numeric_limits<int>::max();

signed main();
void input();
void build();
void Floyd();
void reply();

int c,n,m,d,q;
int w[maxm];
vector<pair<int,int>>s[maxm];

vector<pair<int,int>>g[maxn];

int dis[maxn][maxn]{};

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
#ifndef local
	freopen("subway.in" ,"r",stdin ),
	freopen("subway.out","w",stdout);
#endif
	input(),build(),Floyd();
	while(q--)reply();
	return 0;
}

void input(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			s[a].push_back({i,t});
		}
	}
}

void build(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=inf>>1;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto j:s[i]){
			for(auto k:s[i]){
				int u=j.first,v=k.first,
					w=j.second+k.second;
				dis[u][v]=min(dis[u][v],w),
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
}

void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int w=dis[i][k]+dis[k][j];
				dis[i][j]=min(dis[i][j],w);
			}
		}
	}
}

void reply(){
	int x,y;
	cin>>x>>y;
	int ans=inf;
	for(auto i:s[x]){
		for(auto j:s[y]){
			int u=i.first,v=j.first,
				w=i.second+j.second;
			ans=min(ans,dis[u][v]+w);
		}
	}
	cout<<ans+w[x]+w[y]<<"\n";
}
