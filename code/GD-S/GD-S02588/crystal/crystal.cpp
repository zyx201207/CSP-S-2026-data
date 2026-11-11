#include <bits/stdc++.h>
using namespace std;
long long n,sum[500005],cnt,a[500005],ans;
unsigned long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=n;i>=1;i--)
		sum[i]=sum[i+1]+a[i];
	cnt=n;
	for (int i=n;i>=1;i--)
	{
		while ((i-cnt+1)*a[i]-sum[cnt]+sum[i+1]<=m&&cnt>0)
			cnt--;
		ans=max(i-cnt,ans);
	}
	cout<<ans;
	return 0;
}
