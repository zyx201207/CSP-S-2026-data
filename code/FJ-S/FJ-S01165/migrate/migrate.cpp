#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,a[20005],b[20005],q[20005],x=1;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		b[i]=a[n];
		if(a[x]>=0)
		{
			q[i]=a[1];
		}
		for(int i=1;i<=n;i++)
		{
		    if(a[x]<=0)
		    {
		   	    x++;
			}
			else
			{
			    q[i]=a[x];
			    break;
			}
		}
	} 
	for(int i=1;i<=t;i++)
	{
		cout<<b[i]-q[i]-2;
		if(i!=t)
		{
			cout<<endl;
		}
	}
	return 0;
}
