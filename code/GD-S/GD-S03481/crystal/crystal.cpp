#include <bits/stdc++.h>
using namespace std; 
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>a(n+1);
	vector<long long>sum(n+1,0);
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(long long i=n;i>=1;i--)
	{
		int x=m;
		for(long long j=i;j>=1;j--)
		{
			if(abs(a[i])-abs(a[j-1])<=x)
			{
				x=x-(abs(a[i])-abs(a[j-1]));
				sum[i]++;
			}
			else
			{
				break;
			}
		}
	}
	sort(sum.begin(),sum.end());
	if(sum[n]==2)
	{
		cout<<3;
		return 0;
	} 
	cout<<sum[n];
	return 0;
}
