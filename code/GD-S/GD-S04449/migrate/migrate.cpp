#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
int n,d,a[maxn],b[maxn],c[maxn],dp[maxn],dp2[maxn];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		dp[i]=0;
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(a[mid]-a[i]<=d)l=mid;
			else r=mid-1;
		}
		b[i]=l;
		if(b[i]-i>=1)dp[i]=(b[i+1]-b[i])+dp[b[i+1]-1];
	}
	for(int i=1;i<=n;i++){
		dp2[i]=0;
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]-a[mid]<=d)r=mid;
			else l=mid+1;
		}
		c[i]=l;
		if(i-c[i]>=1)dp2[i]=(c[i]-c[i-1])+dp2[c[i-1]+1];
	}
	int ans=0;
	for(int i=1;i<n;i++)if(b[i]-i>=2)ans+=dp[b[i]-2]*(1+dp2[i+1]);
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	/*
0 2
5 3-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

	*/
	return 0;
}
