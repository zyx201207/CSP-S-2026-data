#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=5e5+5,maxm=1e12+5;
int n,m;
int a[maxn],b[maxn],s1[maxn],s2[maxn],use[maxn];
int dp[maxn],st;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=s1[1]=s2[1]=use[1]=0;
	s1[1]=0;
	for(int i=2; i<=n; i++) {
		b[i]=a[i]-a[i-1];
		s1[i]=b[i]+s1[i-1];
		s2[i]=s1[i]+s2[i-1];
		use[i]=(i-1)*s1[i]-s2[i-1];
	}
	for(int i=1; i<=n; i++) {
		if(use[i]<=m) {
			dp[i]=dp[i-1]+1;
		} else {
			int j=st;
			while(use[i]-(s1[i]-s1[j])>m) {
				j++;
			}
			st=j;
			dp[i]=dp[i-1]-j;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
