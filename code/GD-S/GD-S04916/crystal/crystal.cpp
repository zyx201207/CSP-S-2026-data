#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		long long l=0;
		for(long long j=1;j<i;j++)
		{
			l+=(a[i]-a[j]);
			if(a[i]==a[i+1])
			{
				continue;
			}
			else if(l>=m)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
