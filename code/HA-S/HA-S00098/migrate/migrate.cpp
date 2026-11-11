#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	long long b[10005];
	long long a[10005];
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		if(a[n]-a[t]<d*i)
		{
			b[i]=2;
		}
		else if(a[n]-a[t]==d*i)
		{
			b[i]=1;
		}
		else
		{
			b[i]=0;
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}
