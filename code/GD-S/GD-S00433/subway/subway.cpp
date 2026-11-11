#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
const int D=25;
const long long INF=1e15;
long long w[M];
int co[M][D],cnt[M];
long long dis[N][N];
long long val[M][D];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,q;
	scanf("%d %d %d %d %d",&n,&n,&m,&q,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int x;
			scanf("%d",&x);
			++cnt[x];
			co[x][cnt[x]]=i;
			scanf("%lld",&val[x][cnt[x]]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis[i][j]=dis[j][i]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			int x=co[i][j];
			for(int k=j+1;k<=cnt[i];k++){
				int y=co[i][k];
				dis[x][y]=dis[y][x]=min(dis[x][y],val[i][j]+val[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		long long ans=INF;
		for(int i=1;i<=cnt[s];i++){
			int x=co[s][i];
			for(int j=1;j<=cnt[t];j++){
				int y=co[t][j];
				ans=min(ans,dis[x][y]+val[s][i]+val[t][j]);
			}
		}
		printf("%lld\n",ans+w[s]+w[t]);
	}
	return 0;
}
