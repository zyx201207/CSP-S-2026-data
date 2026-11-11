#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,sum,r=1,ans;
int a[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		if(sum)sum-=a[r]-a[i-1];
		while(sum+(a[r+1]-a[r])*(r-i+1)<=m&&r<n) {
			sum+=(a[r+1]-a[r])*(r-i+1);
			ans=max(ans,r-i+2);
			r++;
		}
		if(r==n)break;
	}
	cout<<ans;
	return 0;
}
