#include<bits/stdc++.h>
#define int long long
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin)),p1==p2?EOF:*p1++)
inline int read(){
	int k=0,f=1;char c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') f=-1;
	for(;isdigit(c);c=gc()) k=k*10+(c^48);
	return k*f;
}
const int N=1e6+5,M=2005;
int n,d,a[N],dis[M][M],lst[M][M],dp[M][M],ans;
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	ans=0;
	for(int i=1;i<=n;i++){
		lst[i][i]=i;
		dis[i][i]=1;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[lst[i][j-1]]<=d) lst[i][j]=lst[i][j-1],dis[i][j]=dis[i][j-1];
			else lst[i][j]=j,dis[i][j]=dis[i][j-1]+1;
//			int pos=lower_bound(a+1,a+n+1,a[j]-a[i]-d);
//			if(j-pos+1)
//			cout<<i<<' '<<j<<' '<<dis[i][j]<<' '<<lst[i][j]<<'\n';
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) dp[i][j]=1;
			else dp[i][j]=0;
		}
	for(int len=3;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for(int k=i+1;k<j;k++){
//				cout<<i<<' '<<k<<' '<<j<<' '<<dis[i][k]<<' '<<dis[k][j]<<' '<<dis[i][j]<<' '<<dp[i][k]<<' '<<dp[k][j]<<' '<<dp[i][j]<<'\n';
				if(dis[i][k]+dis[k][j]==dis[i][j])
					dp[i][j]+=dp[i][k]*dp[k][j]; 
			}
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			if(dp[i][j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,T;
	c=read(),T=read();
	if(c<=10){
		while(T--) solve();
	}
	else{
		while(T--){
			n=read(),d=read();
			for(int i=1;i<=n;i++) a[i]=read(); 
			cout<<(n/2)*(n/2-1)<<'\n';
		}
	}
	return 0;
}

