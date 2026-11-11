#include<bits/stdc++.h>
#define ft first
#define sd second
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int N=503,M=5e5+3,D=23;
const LL INF=0x3f3f3f3f3f3f3f3f;
int w[M],k[N],len[M],c,n,m,d,q;
int vec[M][D];
LL dist[N][N];
int mp[N][M];
int st[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof dist);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
//	printf("len[%d] = %d\n",1650,len[1650]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
//			if(t1==1650) printf("i = %d\n",i);
			if(st[t1]!=i){
				len[t1]++;
				vec[t1][len[t1]]=i;
				mp[i][t1]=t2;
				st[t1]=i;				
			}
		}
	}
//	printf("len[1650] = %d\n",len[1650]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=len[i];j++){
			for(int l=1;l<=len[i];l++){
				if(vec[i][j]==vec[i][l]) continue;
				dist[vec[i][j]][vec[i][l]]=min(dist[vec[i][j]][vec[i][l]],1ll*mp[vec[i][j]][i]+mp[vec[i][l]][i]);
				dist[vec[i][l]][vec[i][j]]=dist[vec[i][j]][vec[i][l]];
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) dist[i][j]=min(dist[i][j],dist[i][l]+dist[l][j]);
				else dist[i][j]=0;
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("dist[%d][%d] = %lld\n",i,j,dist[i][j]);
//		}
//	}
	int cnt=0;
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		LL ans=INF;
//		printf("%d %d\n",x,y);
//		if(cnt<=10) printf("iMya %d %d\n",x,y),cnt++;
		for(int i=1;i<=len[x];i++){
			for(int j=1;j<=len[y];j++){
//				printf("tfeng %lld\n",dist[vec[x][i]][vec[y][j]]);
				if(vec[x][i]==vec[y][j]){
					ans=min(ans,1ll*w[x]+w[y]+mp[vec[x][i]][x]+mp[vec[y][j]][y]);
				}else ans=min(ans,dist[vec[x][i]][vec[y][j]]+1ll*w[x]+w[y]+mp[vec[x][i]][x]+mp[vec[y][j]][y]);
//				if(ans==23&&cnt<=100) printf("%d to %d\n",vec[x][i],vec[y][i]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}