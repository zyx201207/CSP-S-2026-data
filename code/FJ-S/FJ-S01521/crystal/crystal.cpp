#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],sum1,ans,aa[100005],sum2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) aa[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		sort(a+1,a+n+1);
		a[1]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1])
			sum1++;
	}
	sort(aa+1,aa+n+1);
	for(int i=1;i<=n;i++)
	{
		if(aa[i]==aa[i-1])
			sum2++;
	}
	ans=max(sum1,sum2);
	ans++;
	cout<<ans;
	return 0;
}
