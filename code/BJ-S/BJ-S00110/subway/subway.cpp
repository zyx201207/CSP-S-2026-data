#include<bits/stdc++.h>
using namespace std;
int w[500005];
int ns[500005]={0};
int as[500005][22];//i:sta->line
int ts[500005][22];//w:sta->line
long long dl[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",w+i);
	memset(dl,0x3f,sizeof(dl));
	for(int i=1;i<=n;i++){
		int k;
		dl[i][i]=0;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			long long a,t;
			scanf("%lld%lld",&a,&t);
			for(int l=1;l<=ns[a];l++){
				dl[as[a][l]][i]=
				dl[i][as[a][l]]=
				min(dl[i][as[a][l]],min(dl[i][as[a][l]],t+ts[a][l]));
			}
			as[a][++ns[a]]=i;
			ts[a][ns[a]]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
				dl[i][j]=min(dl[i][j],dl[i][k]+dl[k][j]);
		}
	}
	for(int r=1;r<=q;r++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=LONG_LONG_MAX;
		for(int i=1;i<=ns[x];i++){
			for(int j=1;j<=ns[y];j++){
				ans=min(ans,ts[x][i]+dl[as[x][i]][as[y][j]]+ts[y][j]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
