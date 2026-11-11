#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
int ccc,T,n,t[N*2],nt[N*2],h[N],sum,ans,de[N],cnt[N];
ll d,x[N];
void add(int x,int y){t[++sum]=y,nt[sum]=h[x],h[x]=sum;}
void dfs(int u,int deep){
	if(de[u]>deep) de[u]=deep,cnt[u]=0;
	if(de[u]==deep) cnt[u]++;
	for(int i=h[u],v=t[i];i;i=nt[i],v=t[i])
		if(de[v]>de[u]) dfs(v,deep+1);
}
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&ccc,&T);
	while(T--){
		scanf("%d%lld",&n,&d),memset(h,0,sizeof h),sum=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]),de[i]=n+1;
			for(int j=i-1;j>0&&x[i]-x[j]<=d;j--) add(i,j),add(j,i);
		}
		for(int i=1;i<=n;i++){
			dfs(i,0);
			for(int j=1;j<=n;j++) de[j]=n+1,ans+=(cnt[j]==2),cnt[j]=0;
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
