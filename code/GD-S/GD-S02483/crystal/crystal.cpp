#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int BIG=2e6;
int n,m,a[BIG],sum,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int i=1,j=1;
	while(i<=n)
	{
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m&&j<=i)
		{
			sum-=a[i]-a[j];
			j++;
		}
		ans=max(i-j+1,ans);
		i++;
	}
	cout<<ans;
	return 0;
}
