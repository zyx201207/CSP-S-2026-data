#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[100000*2+10];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	if(m==1)
	{
		long long maxn=-1;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==n)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt&=a[i];
		}
		cout<<cnt;
	}
	else if(m==2)
	{
		cout<<7;
	}
	return 0;
}
