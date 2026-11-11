#include<bits/stdc++.h>
using namespace std;
long long int a[10101010],an[10101010],b[1010101];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,ans=0;
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool t=true;
	for(long long int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			t=false;
			break ;
		}
	}
	if(t==true)
	{
		long long int o=0;
		for(long long int i=1;i<=n;i++)
		{
			if((i*(i+1)/2)<=m)
			{
				o=i;
			}
		}
		cout<<o<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	an[0]=0;
	for(long long int i=1;i<=n;i++)
	{
		an[i]=an[i-1]+a[i];
	} 
	for(long long int i=1;i<=n;i++)
	{
		if(a[i]*i-an[i]<=m)
		{
			ans=i;
		}
		else
		{
			break ;
		}
	}
	cout<<ans;
}
