#include<bits/stdc++.h>
using namespace std;

const int MAXM=5e5+10,MAXD=30,MAXN=5e3+10;
const long long MAXK=1e18; 

int c,n,m,d,q;
int l[MAXM][MAXD],cnt[MAXM];
long long w[MAXM],t[MAXM][MAXD],dis[MAXN][MAXN];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j) dis[i][j]=MAXK;
	for (int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for (int j=1;j<=k;j++){
			int a;long long tim;scanf("%d%lld",&a,&tim);
			l[a][++cnt[a]]=i,t[a][cnt[a]]=tim;
		}
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=cnt[i];j++)
			for (int k=j+1;k<=cnt[i];k++)
				dis[l[i][j]][l[i][k]]=dis[l[i][k]][l[i][j]]=min(dis[l[i][j]][l[i][k]],t[i][j]+t[i][k]);
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (i!=j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while (q--){
		int st,ed;scanf("%d%d",&st,&ed);
		long long res=MAXK;
		for (int i=1;i<=cnt[st];i++)
			for (int j=1;j<=cnt[ed];j++)
				res=min(res,w[st]+w[ed]+t[st][i]+t[ed][j]+dis[l[st][i]][l[ed][j]]);
		printf("%lld\n",res);
	}
	return 0;
}
