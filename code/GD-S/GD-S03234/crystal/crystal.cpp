#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],sum,ans=1;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;
	for(int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m)
		{
			sum-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
