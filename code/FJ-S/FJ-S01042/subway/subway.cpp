#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+50;
long long w[M];
long long dp[N][N],dis[N][N],t[M][25];
int a[M][25],num[M],cnt[N];
struct IN{int a,c;};
vector<IN>edge[N];
priority_queue<pair<int,int> >qu;
void djistra(int i){
	dis[i][i]=0;qu.push({0,i});
	memset(cnt,0,sizeof cnt);
	while(qu.size()){
		int v=qu.top().second;qu.pop();
		if(cnt[v])continue;cnt[v]=1;
		for(int j=0;j<edge[v].size();++j){
			int u=edge[v][j].a;
			if(dis[i][v]+edge[v][j].c<dis[i][u]){
				dis[i][u]=dis[i][v]+edge[v][j].c;
				qu.push({-dis[i][u],u});
			}
		}
	}return;
}queue<int>qz;
void bfs(int i){
	dis[i][i]=0;qz.push(i);
	memset(cnt,0,sizeof cnt);
	while(qz.size()){
		int v=qz.front();qz.pop();
		for(int j=0;j<edge[v].size();++j){
			int u=edge[v][j].a;
			if(cnt[u])continue;
			cnt[u]=1;dis[i][u]=dis[i][v]+edge[v][j].c;qz.push(u);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1;j<=k;++j){
			int aa,tt;cin>>aa>>tt;
			a[aa][++num[aa]]=i;
			t[aa][num[aa]]=tt;
		}
	}
	memset(dp,63,sizeof dp);memset(dis,63,sizeof dis);
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;++i){
		sort(a[i]+1,a[i]+num[i]+1);
		for(int j=1;j<=num[i];++j)
	        for(int k=j+1;k<=num[i];++k)
	        	if(dp[a[i][j]][a[i][k]]>t[i][j]+t[i][k])dp[a[i][j]][a[i][k]]=t[i][j]+t[i][k];
	}
	for(int i=1;i<=n;++i)
	    for(int j=i+1;j<=n;++j){
	    	dp[j][i]=dp[i][j];
		}
	
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(dp[i][j]<1e15)edge[i].push_back({j,dp[i][j]});
	if(12<=c&&c<=19)for(int i=1;i<=n;++i)bfs(i);
	else for(int i=1;i<=n;++i)djistra(i);
	while(q--){
		int x,y;long long ans=1e18;cin>>x>>y;
		for(int i=1;i<=num[x];++i)
		    for(int j=1;j<=num[y];++j){
		    	if(dis[a[x][i]][a[y][j]]+t[x][i]+t[y][j]<ans)ans=dis[a[x][i]][a[y][j]]+t[x][i]+t[y][j];
			}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}