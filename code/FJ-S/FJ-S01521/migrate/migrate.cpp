#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],l,sum;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>x[i];
		l=d+d/2;
		for(int j=1;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
			{
				if(k==j+l)
					sum++;
			}
		}
		cout<<sum<<'\n';
		for(int j=1;j<=n;j++) x[i]=0;
		sum=0;
	}
	return 0;
}
