#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MAXM=500005;
#define ll long long
const ll inf=1000000000000000000ll;
ll G[MAXN][MAXN];
int c,n,m,d,q,w[MAXM],t[MAXM][25],ID[MAXM][25],C[MAXM];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int u,ti;scanf("%d %d",&u,&ti);
			C[u]++;ID[u][C[u]]=i,t[u][C[u]]=ti;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)G[i][j]=inf;
	for(int i=1;i<=n;i++)G[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=C[i];j++){
			for(int k=j+1;k<=C[i];k++){
				int ID1=ID[i][j],ID2=ID[i][k];
				G[ID1][ID2]=min(G[ID1][ID2],1ll*t[i][j]+t[i][k]);
				G[ID2][ID1]=min(G[ID2][ID1],G[ID1][ID2]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
				G[j][i]=min(G[j][i],G[i][j]);
			}
		}
	}while(q--){
		int x,y;scanf("%d %d",&x,&y);
		ll ans=inf;
		for(int j=1;j<=C[x];j++){
			for(int k=1;k<=C[y];k++){
				ans=min(ans,G[ID[x][j]][ID[y][k]]+t[x][j]+t[y][k]);
			}
		}ans=ans+w[x]+w[y];
		printf("%lld\n",ans);
	}return 0;
}
