#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],a[500005],t[500005];
long long e[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cs,n,m,d,q;
	scanf("%d%d%d%d%d",&cs,&n,&m,&d,&q);
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
		e[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[j],&t[j]);
		}
		for(int j=1;j<=k[i];j++){
//			if(t[i][j])
			for(int z=j+1;z<=k[i];z++){
				e[a[z]][a[j]]=e[a[j]][a[z]]=min(e[a[j]][a[z]],1ll*(t[j]+t[z]));
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(e[j][i]>1e18)continue;
			for(int z=1;z<=m;z++){
				e[j][z]=min(e[j][z],e[j][i]+e[i][z]);
			}
		}
	}
	int st,en;
	while(q--){
		scanf("%d%d",&st,&en);
		printf("%lld\n",e[st][en]+w[st]+w[en]);
	}
	return 0;
}
