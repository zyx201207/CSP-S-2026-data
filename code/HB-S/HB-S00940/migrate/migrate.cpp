#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int u=0;u<t;u++)
	{
		int n,d;
		cin>>n>>d;
		int a[2000005];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=n-1;i>0;i--)
		{
			a[i]-=a[i-1];
		}
		a[0]=0;
		for(int i=1;i<n-1;i++)
		{
			if(a[i]+a[i+1]<=d)
			{
				a[i]=1;
			}
			else
			{
				a[i]=0;
			}
		}
		int fl=0,save,res=0,remain;
		for(int i=1;i<n-1;i++)
		{
			if(a[i]==1&&a[i+1]==1)
			{
				if(fl==0)
				{
					fl=1;
					save=i;
					remain=i;
				}
				else
				{
					if(i==n-2)
					{
						res+=save*(n-2-remain);
					}
					else
					{
						res+=save*(i-remain);
						save=i-remain;
						remain=i;
					}
				}
			}
		}
			cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
