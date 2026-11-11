#include<bits/stdc++.h>
using namespace std;
int c,t,n,dis[310][310],cnt[310][310],ans;
long long d,x[310];
void dfs(int x,int y,int D,int X){
	if(x==y){
		if(dis[X][y]>D) dis[X][y]=D,cnt[X][y]=1;
		else if(dis[X][y]==D) cnt[X][y]++;
		return;
	}
	for(int i=1;i<=n;i++)if(dis[x][i]==1) dfs(i,y,D+1,X);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;x[j]<=d+x[i]&&j<=n;j++) dis[i][j]=1,cnt[i][j]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)if(dis[i][j]!=1) dfs(i,j,0,i);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) ans+=(cnt[i][j]==2);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
