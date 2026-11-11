#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{	
		int sum=0,f=1;
		for(int i=1;i<n;i++)
		{
			sum+=b[i];
			if(sum>=m)
			{
				ans=i;
				f=0;
				break;
			}
		}
		if(f=0)
		break;
	}
	cout<<ans<<endl;
	return 0;
} 
