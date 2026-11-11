#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#define int long long
using namespace std;
const int N=5005,INF=1e18;
int n,d,f[N][N],dis[N][N],a[N],ans;
vector<int>g[N];
queue<int>q;
inline void init(){
	for(int i=1;i<=n;++i){
		g[i].clear();
		for(int j=1;j<=n;++j)f[i][j]=0,dis[i][j]=INF;
	}
	ans=0;
}
inline void solve(){
	init();
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if(abs(a[i]-a[j])<=d)g[i].push_back(j);
		}
	}
	for(int i=1;i<=n;++i){
		q.push(i);
		f[i][i]=1;
		dis[i][i]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(f[i][u]>1)continue;
			for(int v:g[u]){
				if(dis[i][v]>dis[i][u]+1){
					dis[i][v]=dis[i][u]+1;
					f[i][v]=f[i][u];
					q.push(v);
				}else if(dis[i][v]==dis[i][u]+1){
					f[i][v]+=f[i][u];
				}
			}
		} 
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(f[i][j]==2)++ans;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j)dis[i][j]=INF;
	}
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0; 
}
