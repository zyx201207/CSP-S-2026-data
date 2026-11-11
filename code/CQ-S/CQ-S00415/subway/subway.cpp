#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,a[1000010],top[1000010],dis[510][510];
pair<int,int>b[500010][21];
signed main(){
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&n,&n,&m,&t,&t);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int as;
		scanf("%lld",&as);
		for(int j=1;j<=as;j++){
			int y,x;
			scanf("%lld%lld",&x,&y);
			b[x][++top[x]]={i,y};
		}
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)if(i!=j)dis[i][j]=1e18;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=top[i];j++){
			for(int k=j+1;k<=top[i];k++){
				int as=b[i][j].first,asd=b[i][k].first;
				int x=min(dis[as][asd],b[i][j].second+b[i][k].second);
				dis[as][asd]=dis[asd][as]=x;
//				printf("?%lld %lld %lld?\n",as,asd,b[i][j].second+b[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]); 
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%lld ",dis[i][j]);
//		}
//		printf("\n");
//	}
	for(;t--;){
		int qd,zd,ans=1e18;
		scanf("%lld%lld",&qd,&zd);
		for(int i=1;i<=top[qd];i++){
			for(int j=1;j<=top[zd];j++){
				ans=min(ans,b[qd][i].second+dis[b[qd][i].first][b[zd][j].first]+b[zd][j].second);
			}
		}
		printf("%lld\n",ans+a[qd]+a[zd]);
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
m个地铁站
n条地铁线路 
第i(1<=i<=n)条线路经过 k[i] 个地铁站
dis[i][j]表示第i个路线到第j个路线的时间 
*/
