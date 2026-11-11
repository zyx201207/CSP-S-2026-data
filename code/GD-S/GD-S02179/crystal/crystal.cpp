#include <bits/stdc++.h>
using namespace std;
const int N=5007;
const long long M=1000000000000000007;
long long n,m;
long long a[N];
int ans;
bool check(int x)
{
	long long sum=M;
	for(int i=1;i+x-1<=n;i++)
	{
		long long p=0;
		for(int j=i;j<i+x-1;j++)
		{
			p+=a[i+x-1]-a[j];
	    }
	    sum=min(sum,p);
	}
	if(sum<=m)
	{
		return 1;
	}
	return 0;
}
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
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
		    l=mid+1;
		}
		else
		{
	        r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
