#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000010],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	sum=1;
	for (long long i=1;i<n;i++)
	{
		if (((a[i]-a[i-1])*sum)<=m)
		{
			m-=(a[i]-a[i-1])*sum;
			sum++;
			if (a[i]==a[i+1])
			{
				sum++;
				i++;
			}
		}
		else
		{
			break;
		}
	}
	
	cout<<sum;
	return 0;
 } 
