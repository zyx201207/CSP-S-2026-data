#include<bits/stdc++.h>
using namespace std;
long long ans,t[505][500005],w[500005];
int c,n,m,d,q,x,y,k[505];
int a[505][500005],vis[500005];
void dfs(int xi,int now,long long sum){
	if(now!=xi)
		sum+=t[xi][now];
	if(ans&&sum>=ans)
		return ;
	if(now==y){
		if(!ans)
			ans=sum;
		else
			ans=min(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(t[i][now]&&(i!=xi||now==x)){
			sum+t[i][now];
			for(int j=1;j<=k[i];j++){
				if(vis[a[i][j]])
					continue;
				vis[a[i][j]]=1;
				dfs(i,a[i][j],sum);
				vis[a[i][j]]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			long long z;
			scanf("%d%lld",&a[i][j],&z);
			t[i][a[i][j]]=z;
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		ans=0;
		vis[x]=1;
		dfs(1,x,w[x]+w[y]);
		printf("%lld\n",ans);
	}
	return 0;
}
