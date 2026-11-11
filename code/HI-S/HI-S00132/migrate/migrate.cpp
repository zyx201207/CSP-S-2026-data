#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,d1,ans,step;
long long a[2000100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		cin>>a[i];
		d1=a[2]-a[1];
		step=d/d1;
		if(d<d1*2||n<2*step+1)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			cout<<n-2*step-1<<endl;
			continue;
		}
	}
	return 0;
} 
