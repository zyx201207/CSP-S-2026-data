#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=310,inf=1e15,md=1e9+7;
ll read(){
	ll ans=0,f=1;
	char s=' ';
	while(!(s>='0'&&s<='9')){
		s=getchar();
		if(s=='-')f=-1;
	}
	while(s>='0'&&s<='9'){
		ans=ans*10+s-'0';
		s=getchar();
	}
	return ans*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar('0'+x%10);
}
ll T,n,d,dp[N][N],dis[N][N],ans,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();T=read();
	while(T--){
		n=read();d=read();ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=0,dis[i][j]=inf;
		for(int i=1;i<=n;i++)x[i]=read();
		for(int i=1;i<=n;i++){
			dp[i][i]=1;dis[i][i]=0;
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n&&x[k]-x[j]<=d;k++){
					if(dis[i][j]+1<dis[i][k]){
						dis[i][k]=dis[i][j]+1;
						dp[i][k]=dp[i][j];
					}else if(dis[i][j]+1==dis[i][k])dp[i][k]+=dp[i][j];
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dp[i][j]==2)ans++;
		write(ans);putchar('\n');
	}
	return 0;
}

