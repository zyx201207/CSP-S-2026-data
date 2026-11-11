#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		int cnt=0,s=m;
		for(int j=1;j<=i;j++)
		{
			if(a[i]-a[j]<=s)
			{
				s=s-a[i]+a[j];
				cnt++;
			}
		}
		sum=max(cnt,sum);
	}
	cout<<sum;
	return 0;
}
