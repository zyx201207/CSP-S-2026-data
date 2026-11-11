#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=-1e18;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	for(long long i=a[1]+1;i<=a[n];i++)
	{
		long long cnt=0,sum=0,mini=0;
		for(long long j=1;j<=n;j++)
			if(a[j]>i)
			{
				mini=j-1;
				break;
			}
		for(long long j=mini;j>=1;j--)
		{
			sum+=(i-a[j]);
			if(sum>m)
				break;
			else if(sum<=m)
			{
				cnt++;
			}
		}
		if(ans<cnt)
		{
			ans=cnt;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
