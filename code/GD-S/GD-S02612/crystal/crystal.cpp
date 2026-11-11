#include<bits/stdc++.h>
using namespace std;
long long n,m,d,f=-1,g,h,ans,ans1,ans3=1,q,w;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		d=abs(a[i]-a[i+1]);
		if(a[i]==i)
		{
			ans=1;
		}
		else
		{
			ans=0;
		}
		if(d>f)
		{
			f=d;
			g=i;
		}
		ans+=d;
	}
	w=d=abs(a[0]-a[1]);
	for(int i=0;i<n-1;i++)
	{
		q=abs(a[i]-a[i+1]);
		if(q==w)
		{
			ans=2;
		}
		else
		{
			ans=0;
		}
	}
	if(q==0&&ans==2)
	{
		cout<<a[0];
	}
	for(int i=0;i<g;i++)
	{
		ans1+=a[g]-a[i];
		if(ans1>m)
		{
			cout<<ans3;
			return 0;
		}
		ans3++;
	}
	cout<<ans3;
 } 
