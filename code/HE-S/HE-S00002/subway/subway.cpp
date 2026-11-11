#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q,w[500010],dis[510][510],a[500010][25],t[500010][25],cnt[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%lld %lld",&x,&y);
			cnt[x]++;
			a[x][cnt[x]]=i;
			t[x][cnt[x]]=y;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=0;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
				dis[a[i][k]][a[i][j]]=min(dis[a[i][k]][a[i][j]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v,ans=1e18;
		scanf("%lld %lld",&u,&v);
		for(int j=1;j<=cnt[u];j++){
			for(int k=1;k<=cnt[v];k++){
				ans=min(ans,dis[a[u][j]][a[v][k]]+t[u][j]+t[v][k]);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
