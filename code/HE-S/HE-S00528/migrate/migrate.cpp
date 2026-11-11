#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],b[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	bool bo=true;
	int l=0;
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i];
		}
		for(int j=1;j<n;j++)
		{
			b[j]=a[j+1]-a[j];
		}
		for(int j=1;j<n-1;j++)
		{
			if(b[j]!=b[j+1])
			{
				bo=false;
			}
		}
		for(int j=1;j<n-1;j++)
		{
			if(b[j]>d)
			{
				l=j;
				break;
			}
		}
		for(int j=1;j<l;j++)
		{
			if(b[j]+b[j+1]>d)
			{
				l=i;
				break;
			}
		}
		if(bo==true&&b[1]*2<=d)
		{
			cout<<n-3<<endl;
			continue;
		}
		else if(bo==true)
		{
			cout<<"0"<<endl;
		}
		if(l-3<=0)
		{
			cout<<"0"<<endl;
			continue;
		}
		cout<<l-3<<endl;
	}
	return 0;
}
