#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],a[505][20005],s[505];
long long mn,trs[505][505],t[505][20005];
bool sta[20005][30],vis[505];
void dfs(int ln,int x,int st,int gl,long long now) {
	vis[ln]=1;
	if(sta[gl][ln])
	{
		mn=min(mn,now+t[x][st]+t[ln][gl]);
		return;
	} 
	for(int i=1;i<=n;i++) 
		if(trs[ln][i]!=1e18&&!vis[i]) dfs(i,x,st,gl,now+trs[ln][i]); 
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)
		scanf("%d",&w[i]);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i][0]);
		for(int j=1; j<=a[i][0]; j++) {
			scanf("%d",&a[i][j]);
			scanf("%lld",&t[i][a[i][j]]);
			s[a[i][j]]++;
			sta[a[i][j]][i]=1;
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			trs[i][j]=1e18;
	for(int i=1; i<=m; i++) {
		if(s[i]<2) continue;
		for(int j=1; j<=n; j++)
			for(int k=j+1; k<=n; k++){
				if(sta[i][j]&&sta[i][k]) trs[j][k]=trs[k][j]=min(trs[j][k],t[j][i]+t[k][i]);
			}
	}
	while(q--) {
		int st,en;
		scanf("%d%d",&st,&en);
		long long ans=w[st]+w[en];
		mn=1e18;
		for(int i=1; i<=n; i++)
		{
			memset(vis,0,sizeof vis);
			if(sta[st][i]) dfs(i,i,st,en,0);
		}	
		printf("%lld\n",ans+mn);
	}
	return 0;
}
