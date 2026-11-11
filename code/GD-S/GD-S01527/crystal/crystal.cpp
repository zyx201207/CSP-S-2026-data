#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,a[N],sum[N];
int n;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	sum[0]=0LL;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0,l=1;
	for(int i=1;i<=n;i++) {
		while((i-l+1)*a[i]-sum[i]+sum[l-1]>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
