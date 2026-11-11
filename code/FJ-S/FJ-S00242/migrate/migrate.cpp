/*骗分：n<=5000区间dp,A等差数列 
注意到如果存在两个岛屿之间无法相互抵达，就可以分段，这样可以加速 
dp[l][r]从l到r的最短路径的数量
len[l][r]从l到r最短路径的长度 
枚举中间点k：  */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N1=5001,N=2e6+1;
inline ll read(){
	ll x=0,k=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')k=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return k*x;
}
int c,t,n;
int len[N1][N1],sep[N1];
ll dp[N1][N1],d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c<=10){
		while(t--){
			n=read();d=read();sep[0]=1; 
			ll ans=0,lst,cnt=0;
			memset(len,0x3f,sizeof(len));
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;++i){
				a[i]=read();
				if(i!=1&&a[i]-lst>d){
					sep[++cnt]=i;
				}
				lst=a[i];
			} 
			sep[++cnt]=n+1;
			//预处理:原地，一次能到的点，滑窗
			for(int i=1;i<=n;++i)len[i][i]=0,dp[i][i]=1;
			for(int x=1;x<=cnt;++x){
				int L=sep[x-1],R=sep[x]-1;
				int r=1;
				for(int l=1,r=l+1;l<R;++l){
					ll lengh=0;
					while(1){
						++r;
						lengh=a[r]-a[l];
						if(lengh<=d) len[l][r]=1,dp[l][r]=1;
						else break;
						
					}
				}
			}
			//dp
			for(int x=1;x<=cnt;++x){
				int L=sep[x-1],R=sep[x]-1;
				for(int lengh=2;lengh<=R-L+1;++lengh){
					for(int l=1;l+lengh-1<=R;++l){
						int r=l+lengh-1;
						for(int x=l;x<r;++x){
							for(int y=x+1;y<r;++y){
								int curStep=len[l][x]+len[y][r];
								if(len[l][r]>curStep){
									len[l][r]=curStep;
									dp[l][r]=dp[l][x]*dp[y][r];
								}
								else if(len[l][r]==curStep)dp[l][r]+=dp[l][x]*dp[y][r];
							}
							
						}
						ans+=(dp[l][r]==2);
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
}
