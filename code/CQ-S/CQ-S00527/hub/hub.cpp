#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
#define popc __builtin_popcount
int c,t,n,k,dis[105][105],D[105],ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		int n,k;scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1000000000;
			}
		}for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int i=1;i<n;i++){
			int u,v;scanf("%d %d",&u,&v);
			dis[u][v]=dis[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				}
			}
		}ans=1000000000;
		for(int S=0;S<(1<<n);S++){
			if(popc(S)!=k)continue;
			int E=0;
			for(int u=1;u<=n;u++){
				for(int v=u+1;v<=n;v++){
					if(((S>>(u-1))&1)&((S>>(v-1))&1)){
						if(dis[u][v]==1)E++;
					}
				}
			}
			if(E!=k-1&&E!=k-2)continue;
			for(int i=1;i<=n;i++)D[i]=1000000000;
			for(int u=1;u<=n;u++){
				if((S>>(u-1))&1){
					for(int i=1;i<=n;i++)D[i]=min(D[i],dis[i][u]);
				}
			}int MAX=0;
			for(int i=1;i<=n;i++)MAX=max(MAX,D[i]);
			ans=min(ans,MAX);
		}printf("%d\n",ans);
	}return 0;
}
