#include<bits/stdc++.h>
using namespace std;using ll=long long;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=505,M=5e5+5;
int n,m,d,q,cid;
ll dis[N][N],W[M];
vector<pair<int,ll>> ps[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=rd();
	n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++)W[i]=rd();
	for(int i=1;i<=n;i++){
		int k=rd();
		while(k--){
			int x=rd(),t=rd();
			ps[x].push_back({i,t});
		}
	}
	memset(dis,60,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<ps[i].size();j++)for(int k=j+1;k<ps[i].size();k++){
			int u=ps[i][j].first,v=ps[i][k].first;
			dis[u][v]=dis[v][u]=min(dis[u][v],ps[i][j].second+ps[i][k].second);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=rd(),y=rd();
		ll ans=1e18;
		for(auto [p1,t1]:ps[x])for(auto [p2,t2]:ps[y])
			ans=min(ans,dis[p1][p2]+t1+t2);
		printf("%lld\n",ans+W[x]+W[y]);
	}
	return 0;
}

