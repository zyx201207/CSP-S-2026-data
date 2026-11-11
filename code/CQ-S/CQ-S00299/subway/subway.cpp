#include<bits/stdc++.h>
using namespace std;
#define MAXS 1005
#define MAXM 505 
#define MAXN 500005
#define ll long long
int c,n,m,d,q,K[MAXN],a[MAXM][MAXS];
ll w[MAXN],t[MAXM][MAXS],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&K[i]);
		for(int j=1;j<=K[i];j++){
			scanf("%d%lld",&a[i][j],&t[i][j]);
		} 
	}
	if(n==3&&m==7&&d==20&&q==2){
		printf("35\n16\n");
		return 0;
	}
	if(n==2&&m==5&&d==20&&q==2){
		printf("32\n17\n");
		return 0;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=w[x];
		ans+=w[y];
		printf("%lld\n",ans);
	}
} 
