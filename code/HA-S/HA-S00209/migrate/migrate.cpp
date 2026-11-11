#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10;
ll n,d,a[N],dp[N],dp1[N];
ll l[N],r[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		for(ll i=1; i<=n; i++) {
			cin>>a[i];
			dp[i]=dp1[i]=0;
		}
		for(ll i=1,j=1,k=0; i<=n; i++) {
			while(j<=n&&a[j]+d<a[i]) j++;
			while(k+1<=n&&a[k+1]+d<a[i+1]) k++;
			l[i]=j,r[i]=k;
			if(r[i]!=0&&l[i]<=r[i]) dp[i]=(r[i]-l[i]+1)+dp[l[i]];
			if(r[i]==i) dp[i]--;
		}
		for(ll i=n,j=n+1,k=n; i>=1; i--) {
			while(j-1>=1&&a[j-1]-d>a[i-1]) j--;
			while(k>=1&&a[k]-d>a[i]) k--;
			l[i]=j,r[i]=k;
			if(l[i]!=n+1) dp1[i]=(r[i]-l[i]+1)+dp1[r[i]];
			if(l[i]==i) dp1[i]--;
		}
		ll ans=0;
		for(ll i=1,j=1; i<=n; i++) {
			while(j+1<=n&&a[j+1]<=a[i]+d) j++;
			if(a[i-1]+d>=a[j]) continue; 
			if(j==n) break;
			ll t=j-1;
			if(t>i){
				ans+=((r[t]-l[t]+1)+dp1[r[t]])*(dp[i]+1);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//£¿Íêµ°ÁË¡£ 

