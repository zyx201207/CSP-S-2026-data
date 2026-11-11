#include <bits/stdc++.h>
#define N 505
#define M 500005
#define int long long
using namespace std;
int c,n,m,d,q,w[M],K,a,t,Vn[M][25],Va[M][25],cnt[M],x,y,dp[N][N];
int read(){
	int x=0;
	char ch=getchar();
	bool f=false;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=true;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		K=read();
		for(int j=1;j<=K;++j){
			a=read(),t=read();
			Vn[a][++cnt[a]]=i;
			Va[a][cnt[a]]=t;
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;++i){
		for(int j=1;j<=cnt[i];++j){
			for(int k=j+1;k<=cnt[i];++k){
				int u=Vn[i][j],v=Vn[i][k],w=Va[i][j]+Va[i][k];
				dp[u][v]=dp[v][u]=min(dp[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;++i){
		dp[i][i]=0;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		x=read(),y=read();
		int ans=1e18;
		for(int i=1;i<=cnt[x];++i){
			for(int j=1;j<=cnt[y];++j){
				int u=Vn[x][i],v=Vn[y][j];
				ans=min(ans,dp[u][v]+Va[x][i]+Va[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
