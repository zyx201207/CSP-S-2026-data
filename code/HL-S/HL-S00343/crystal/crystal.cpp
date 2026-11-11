#include<bits/stdc++.h>
using namespace std;
long long a[50001],b[50001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int x=a[(n+1)/2];
	for(int i=1;i<=n;i++)
	{
		b[i]=abs(x-a[i]);
	}
	sort(b+1,b+1+n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=b[i];
		if(sum>m)
		{
			cout<<i-1;
			break;
		}
	}
	return 0;
}
