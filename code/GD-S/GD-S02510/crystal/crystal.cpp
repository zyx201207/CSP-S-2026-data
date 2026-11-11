#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
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
	long long maxsum=0;
	for(int i=1;i<=n;i++)
	{
		long long m1=m,sum=0,end;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==a[i])
			{
				end=j;
				sum++;
			}
			else if(a[j]>a[i])
			{
				break;
			}
		}
		for(int j=i-1;j>=1;j--)
		{
			if(m1-(a[i]-a[j])<0)
			{
				break;
			}
			else if(a[j]!=a[i])
			{
				sum++;
				m1-=(a[i]-a[j]);
			}
		}
		maxsum=max(maxsum,sum);
		i=end;
	}
	cout<<maxsum;
	return 0;
}
