#include<bits/stdc++.h>
using namespace std;
long long a[500009];
bool f(long long a,long long b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,f);
	long long ans=0;
	{
		long long sum=1,x=0;
		for(long long j=1;j<n;j++)
		{
			if(x+(a[j+1]-a[j])*(j)<=m)
			{
				x+=(a[j+1]-a[j])*(j);
				sum++;
			}
			else break;
		}
		ans=max(ans,sum);		
	}
	cout<<ans;
	return 0;
} 
