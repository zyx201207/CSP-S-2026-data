#include<bits/stdc++.h>
#define ll long long
#define f(i,a,b,n) for(ll i=a;i<=b;i+=n)
using namespace std;
ll c,n,m,d,q,w[500002],K,a,t,x,y,L[500002][22],T[500002][22],dis[502][502],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof(dis));
	f(i,1,n,1) dis[i][i]=0;
	f(i,1,m,1) scanf("%lld",&w[i]);
	f(i,1,n,1){
		scanf("%lld",&K);
		while(K--){
			scanf("%lld%lld",&a,&t);
			L[a][++L[a][0]]=i;
			T[a][++T[a][0]]=t;
			f(k,1,L[a][0]-1,1)
				dis[L[a][k]][i]=min(dis[L[a][k]][i],T[a][k]+t),
				dis[i][L[a][k]]=min(dis[i][L[a][k]],T[a][k]+t);
		}
	}
	f(k,1,n,1) f(i,1,n,1) if(k!=i) f(j,1,n,1) if(k!=j&&i!=j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans=0x3f3f3f3f3f3f3f3f;
		f(i,1,L[x][0],1) f(j,1,L[y][0],1) ans=min(ans,dis[L[x][i]][L[y][j]]+w[x]+w[y]+T[x][i]+T[y][j]);
		printf("%lld\n",ans);
	}
	return 0;
}
