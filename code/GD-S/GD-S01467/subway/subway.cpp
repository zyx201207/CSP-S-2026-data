#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10,M=5e5+10,inf=1e18;
int c,n,m,D,q;
int w[M],k[N],dis[N][N];
vector<pair<int,int>>Sta[M];
void floyid(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)if(i!=k){
			for(int j=1;j<=n;j++)if(i!=j&&j!=k){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			int a,t;scanf("%lld%lld",&a,&t);
			Sta[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<Sta[i].size();j++){
			for(int k=j+1;k<Sta[i].size();k++){
				int subx=Sta[i][j].first,suby=Sta[i][k].first;
				dis[subx][suby]=dis[suby][subx]=min(dis[subx][suby],Sta[i][j].second+Sta[i][k].second);
			}
		}
	}
	floyid();
	while(q--){
		int x,y;scanf("%lld%lld",&x,&y);
		int ans=inf;
		for(int i=0;i<Sta[x].size();i++){
			for(int j=0;j<Sta[y].size();j++){
				int subx=Sta[x][i].first,suby=Sta[y][j].first;
				int sum=w[x]+w[y]+Sta[x][i].second+Sta[y][j].second+dis[subx][suby];
				ans=min(ans,sum);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
