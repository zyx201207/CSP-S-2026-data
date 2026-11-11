#include<bits/stdc++.h>
using namespace std;
int c,t,n[1000005],d[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		long long x[10000005],sum=0;
		for(int j=1;j<=n[i];j++)
		{
			cin>>x[i];
		}
		sum=n[i]-d[i]-1;
		cout<<sum;
	}
	return 0;
 } 
