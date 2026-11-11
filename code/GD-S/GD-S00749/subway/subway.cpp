#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
//void write(int x){
//	if(x<0)putchar('-'),x=-x;
//	if(x<10)putchar(x+'0');
//	else write(x/10),putchar(x%10+'0');
//	return ;
//}
const int N = 500;
const int M = 5e5;
int w[M+7];
int k[N+7];
int a[M+7][25];
int t[M+7][25];
int cnt[M+7];
int dp[N+7][N+7];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int aa=read(),tt=read();
			a[aa][++cnt[aa]]=i;
			t[aa][cnt[aa]]=tt;
		} 
	}
	//init begin
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		for(int z1=1;z1<=cnt[i];z1++){
			int v1=a[i][z1],t1=t[i][z1];
			for(int z2=z1;z2<=cnt[i];z2++){
				int v2=a[i][z2],t2=t[i][z2];
				if(v1==v2)dp[v1][v2]=dp[v2][v1]=0;
				else{
					dp[v1][v2]=dp[v2][v1]=min(dp[v1][v2],t1+t2);
				}
			}
		} 
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][k]+dp[k][j]<dp[i][j])
					dp[i][j]=dp[i][k]+dp[k][j];
			}
		}
	}
	//init end
	while(q--){
		int st=read(),en=read(),ans=0,mi=0x3f3f3f3f3f3f3f3f;
		
		ans+=w[st]+w[en];
		for(int z1=1;z1<=cnt[st];z1++){
			int v1=a[st][z1],t1=t[st][z1];
			for(int z2=1;z2<=cnt[en];z2++){
				int v2=a[en][z2],t2=t[en][z2];
				mi=min(mi,dp[v1][v2]+t1+t2);
			}
		}
		ans+=mi;
		printf("%lld\n",ans);
	}
	return 0;
}
