#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5,D=25,INF=0x3f3f3f3f;
const ll LINF=1ll*INF*INF;
struct Node{
	int cnt,to[D];
	ll value[D];
};
int c,n,m,d,q;
ll f[N][N],w[M];
Node mp[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=N-5;i++)
		for(int j=1;j<=N-5;j++)
			f[i][j]=LINF;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]),mp[i].cnt=0;
	for(int i=1,k;i<=n;i++){
		f[i][i]=0;
		scanf("%d",&k);
		for(int j=1,to,value,num;j<=k;j++){
			scanf("%d%lld",&to,&value);
			num=++mp[to].cnt;
			mp[to].to[num]=i;
			mp[to].value[num]=value;
		}
	}
	for(int k=1;k<=m;k++){
		int u,v;
		ll value;
		for(int i=1;i<=mp[k].cnt;i++)
			for(int j=1;j<=mp[k].cnt;j++){
				if(i==j) continue;
				u=mp[k].to[i],v=mp[k].to[j],value=mp[k].value[i]+mp[k].value[j];
				f[u][v]=min(f[u][v],1ll*value);
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=1;j<=n;j++)
					if(i!=j&&j!=k)
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int be,ed;
		ll ans=LINF;
		scanf("%d%d",&be,&ed);
		for(int i=1,u,v;i<=mp[be].cnt;i++)
			for(int j=1;j<=mp[ed].cnt;j++){
				u=mp[be].to[i],v=mp[ed].to[j];
				ans=min(ans,w[be]+w[ed]+mp[be].value[i]+mp[ed].value[j]+f[u][v]);
			}
		printf("%lld\n",ans);
	}
	return 0;
}

