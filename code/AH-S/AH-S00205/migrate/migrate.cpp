#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int n[1000000];
int d[1000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int j=0;j<t;j++)
	{
		cin>>n[j];
		cin>>d[j];
		for(int i=0;i<n[j];i++)
	    {
		    cin>>a[i];
	    }
	}
	for(int j=1;j<=t;j++)
	{
		for(int k=0;k<n[j]-2;k++)
		{
			if(a[k]+d[j]<a[k+1])
			{
				cout<<0<<endl;
			}
			if(a[k]+d[j]>=a[k+1]||a[k]+d[j]<a[k+2])
			{
				continue;
			}
		}
	}
	return 0;
}

