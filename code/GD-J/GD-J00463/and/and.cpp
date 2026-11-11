#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5,M=2e7;
ll m,n,a[N+10],f,g,ma,s,dp[2][M+10],maxx;
bool pd(ll x) {
	for(;x>0;x/=2) {
		if(x%2) return false;
	}
	return true;
}
void bl() {
	for(int i=1;i<=n;i++) {
		dp[1][a[i]]=1;
		for(int j=0;j<=ma*2;j++) {
			if(dp[0][j]&&(j&a[i])<=ma*2) dp[1][j&a[i]]=max(dp[1][j&a[i]],max(dp[0][j&a[i]],dp[0][j]+1));
		}
		for(int j=0;j<=ma*2;j++)
			dp[0][j]=max(dp[0][j],dp[1][j]),dp[1][j]=0;
	}
	for(ll j=0;j<=ma*2;j++) {
		if(dp[0][j]>=m) maxx=max(maxx,j);
	}
	cout<<maxx;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=i-1) f=1;
		if(pd(a[i])==false) g=1;
		ma=max(ma,a[i]);
		if(i==1) s=a[i];
		s&=a[i];
	}
	if(n<=20) {
		bl();
	}
	else if(n<=2000) {
		if(m==1) cout<<ma;
		else if(m==n) cout<<s;
		else if(m==2) {
			ll ma2=0;
			for(int i=1;i<=n;i++) {
				for(int j=i+1;j<=n;j++)
					ma2=max(ma2,a[i]&a[j]);
			}
			cout<<ma2;
		}
		else {
			bl();
		}
	}
	else{
		if(m==n-1) {
			cout<<ma;
		}
		else if(pd(n)&&f==0) {
			sort(a+1,a+n+1);
			ll ans=a[n];
			for(int i=n-1;i>=max(1ll,n-m+1);i--)
				ans&=a[i];
			cout<<ans;
		}
		else if(g==0) {
			sort(a+1,a+n+1);
			ll ans=a[n];
			for(int i=n-1;i>=n-m+1;i--)
				ans=ans&a[i];
			cout<<ans;
		}
		else {
			bl();
		}
	}
	

	return 0; 
}
