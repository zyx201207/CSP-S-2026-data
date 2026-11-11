#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,a[510000],cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		long long c=0,p=m;
		for(int j=i;j>=0;j--)
		{
			if(a[j]==a[i])
			{
				c++;
			}
			else if(p>=a[i]-a[j])
			{
				p=p-a[i]+a[j];
				c++;
			}
			else break;
		}
		cnt=max(c,cnt);
	}
	cout<<cnt;
	return 0;
}
