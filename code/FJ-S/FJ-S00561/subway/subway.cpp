#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e4+5;
const int N=505;
int c,n,m,d,T;
int w[M],k[N],a[N][M],t[N][M];
int x,y;
ll dis[1005][1005];
void solve(){
	scanf("%d%d",&x,&y);
	printf("%lld\n",w[x]+w[y]+dis[x][y]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&T);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int _=1;_<=n;_++){
		for(int i=1;i<=k[_];i++){
			for(int j=i+1;j<=k[_];j++){
				dis[a[_][i]][a[_][j]]=min(dis[a[_][i]][a[_][j]],(ll)t[_][i]+t[_][j]);
				dis[a[_][j]][a[_][i]]=dis[a[_][i]][a[_][j]];
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			printf("%lld ",dis[i][j]);
//		}
//		printf("_\n");
//	}
	for(int _=1;_<=m;_++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][j]>dis[i][_]+dis[_][j]) dis[i][j]=dis[i][_]+dis[_][j];
				dis[j][i]=dis[i][j];
			}
		}
	}
	while(T--){
		solve();
	}
	return 0;
}
