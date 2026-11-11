#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=2,j=1;i<=n;i++)
	{ while((i-j)*a[i]-sum[i-1]+sum[j-1]>m&&j<i) j++;
	  ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}