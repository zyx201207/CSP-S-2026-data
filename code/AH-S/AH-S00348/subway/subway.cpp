#include<bits/stdc++.h>
#define ll long long
#define M 500005
#define N 505
using namespace std;
int c,n,m,d,q,num[N];
int bel[M][22],nbel[M];
ll mp[N][N];
ll cost[M][22],w[M],dp[N][N];
ll read(){
	bool flag=false;
	char c;
	ll num=0;
	c=getchar_unlocked();
	while(!(c>='0'&&c<='9')){
		if(c=='-') flag=true;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		num*=10;
		num+=c-'0';
		c=getchar_unlocked();
	}
	return flag?-num:num;
}
void floyd(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dp[i][j]=mp[i][j];
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
}	
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int u,val,i=1;i<=n;i++){
		num[i]=read();
		for(int j=1;j<=num[i];j++){
			u=read();val=read();
			nbel[u]++;
			bel[u][nbel[u]]=i;
			cost[u][nbel[u]]=val;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j) mp[i][j]=1e18;
	for(int u,v,i=1;i<=m;i++){
		for(int j=1;j<=nbel[i];j++)
		for(int k=j+1;k<=nbel[i];k++){
			u=bel[i][j];
			v=bel[i][k];
			mp[u][v]=min(mp[u][v],cost[i][j]+cost[i][k]);
			mp[v][u]=mp[u][v];
		}
	}
	floyd();
	int u,v;
	while(q--){
		u=read();v=read();
		ll ans=1e18;
		for(int i=1;i<=nbel[u];i++)
		for(int j=1;j<=nbel[v];j++){
			ans=min(ans,cost[u][i]+dp[bel[u][i]][bel[v][j]]+cost[v][j]);
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
