#include<bits/stdc++.h>
using namespace std;
int c,t,n,sum=0,k;
long long d,x[2000000],Sum=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
	    cin>>n>>d;
	    for(int j=1;j<=n;j++)
	    {
			cin>>x[j];
		}
		if(x[n]-x[1]<=d)
		{
			cout<<0<<endl;
			continue;
	    }
		k=x[2]-x[1];
		for(int j=3;j<=n;j++)
	    {
			if(x[j]-x[j-1]==k) sum++;
		}
		if(sum==n-2)
		{
			d/=k;
			if(d>1)
			{
				Sum=d*(d-1)/2*(n-(d*2)+1);
				cout<<Sum<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		sum=0;
    }
}
