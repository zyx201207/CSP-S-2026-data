#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+5;
ll a[maxn],sum[maxn]; int n; ll m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i]; 
	int ans=0; int j=0;
	for(int i=1;i<=n;i++)
	{
		while((a[i]*((ll)i-j)-(sum[i]-sum[j]))>m) j++;
		ans=max(ans,i-j);
	}
	cout<<ans<<"\n";
	return 0;
}
