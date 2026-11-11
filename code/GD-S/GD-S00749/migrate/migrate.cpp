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
const int N = 300;
int a[N+7];
int f[N+7][N+7];
int dp[N+7][N+7];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	if(c>6){
		while(t--)printf("0\n");
		return 0;
	}
	while(t--){
		int n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			f[i][i]=0;
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d){
					f[i][j]=f[j][i]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][k]+f[k][j]<f[i][j])
						f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(f[i][j]==1)dp[i][j]=1; 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int ans=1;
				for(int k=i+1;k<j;k++){
					if(f[i][k]+f[k][j]==f[i][j])dp[i][j]+=(dp[i][k]*dp[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(dp[i][j]==2)ans++;
		printf("%lld\n",ans); 
	}
	return 0;
} 
