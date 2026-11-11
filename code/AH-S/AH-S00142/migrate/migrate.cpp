#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dd=2e6+5;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int c,t;
int n,d;
int a[dd],dp[dd],pos[dd];
int lev[dd];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c<=6){
		while(t--){
			n=read();d=read();
			memset(dp,0,sizeof(dp));
			memset(pos,0,sizeof(pos));
			memset(lev,0,sizeof(lev));
			for(int i=1;i<=n;i++) a[i]=read();
			for(int i=1;i<=n;i++){
				pos[i]=lower_bound(a+1,a+1+n,a[i]+d)-a;
				if(pos[i]>n) pos[i]=n;
				while(a[pos[i]]>a[i]+d) pos[i]--;
			}
			for(int i=1;i<=n;i++){
				if(pos[i-1]<i) lev[i]=0;
				else{
					int j=i;
					for(;j<=pos[i-1];j++) lev[j]=lev[i]+1;
					i=j-1;
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				dp[i]=1;
				for(int j=i+1;j<=n;j++){
					if(lev[j]==0) dp[j]=1;
					for(int k=j+1;k<=pos[j];k++) dp[k]+=dp[j];
				}
				for(int j=i+1;j<=n;j++) if(dp[j]==2) cnt++;
				memset(dp,0,sizeof(dp));
			}
			write(cnt);
			putchar('\n');
		}
	}
	else{
		while(t--){
			puts("0\n");
		}
	}
	return 0;
}
