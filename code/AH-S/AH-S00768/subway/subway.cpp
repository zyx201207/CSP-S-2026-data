#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>p[500005];
int w[500005],t1[505][20005],t2[5][500005],dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,a,tmp,x,y,minn;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",w+i);
	memset(dis,0x3f,sizeof dis);
	if(c<=15){
		for(int i=1;i<=n;i++){
			scanf("%lld",&k);
			dis[i][i]=0;
			for(int j=1;j<=k;j++){
				scanf("%lld%lld",&a,&tmp);
				t1[i][a]=tmp;
				for(int v:p[a])
					dis[i][v]=dis[v][i]=min(dis[i][v],t1[i][a]+t1[v][a]);
				p[a].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
		while(q--){
			scanf("%lld%lld",&x,&y);
			minn=dis[0][0];
			for(int i:p[x])
				for(int j:p[y])
					minn=min(minn,dis[i][j]+t1[i][x]+t1[j][y]);
			printf("%lld\n",minn+w[x]+w[y]);
		}
	}
	if(c>=20&&c<=21){
		for(int i=1;i<=n;i++){
			scanf("%lld",&k);
			dis[i][i]=0;
			for(int j=1;j<=k;j++){
				scanf("%lld%lld",&a,&tmp);
				t2[i][a]=tmp;
				for(int v:p[a])
					dis[i][v]=dis[v][i]=min(dis[i][v],t2[i][a]+t2[v][a]);
				p[a].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
		while(q--){
			scanf("%lld%lld",&x,&y);
			minn=dis[0][0];
			for(int i:p[x])
				for(int j:p[y])
					minn=min(minn,dis[i][j]+t2[i][x]+t2[j][y]);
			printf("%lld\n",minn+w[x]+w[y]);
		}
	}
	return 0;
}
