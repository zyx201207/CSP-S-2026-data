#include <bits/stdc++.h>
using namespace std;
long long dis[2000005], a[2000005], dp[2000005];
long long n, d;
bool pd;
inline long long read(){
	long long s(0), f(1), ch=getchar();
	for(;ch<'0' || ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0' && ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+ch-'0';
	return s*f;
}
struct o{
	int s, id;
};
bool solve(int u, int v){
	for(int i=u;i<=v;i++) dis[i]=1e18;
	dis[u]=0;
	dp[u]=1;
	for(int i=u;i<v;i++){
		if(dis[i]==1e18){
			pd=0;
			return 0;
		}
		for(int j=i+1;j<=v && a[i]+d>=a[j];j++){
			if(dis[j]==dis[i]+1){
				dp[j]+=dp[i];
			}		
			else if(dis[j]>dis[i]+1){
				dis[j]=dis[i]+1;
				dp[j]=dp[i];
			}
		} 
	}
	return (dp[v]==2);
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c=read(), T=read();
	if(c<=10){
		while(T--){
			long long ans=0;
			n=read(), d=read();
			for(int i=1;i<=n;i++){
				a[i]=read();
			}
			for(int i=1;i<=n;i++){
				pd=1;
				for(int j=i+1;j<=n && pd;j++){
					ans+=solve(i, j);
				}
			}
			cout << ans << '\n';
		}
		return 0;		
	}
	while(T--){
		n=read(), d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		long long jx=a[2]-a[1];
		long long x=d/jx;
		cout << (n-2*x+1) << '\n';
	}
	return 0;
}
