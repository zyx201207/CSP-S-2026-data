#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=0,sum=0,ans=0;
	while (r<=n) {
		while (sum<=m&&r<=n) {
			ans=max(ans,r-l+1);
			r++;
			sum+=(a[r]-a[r-1])*(r-l);
		}
		while (sum>m&&l<=r) {
			sum-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
}
