#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long c[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	bool f=1;
	long long i,j,ans=0;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=1;i<n-1;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i])
			f=0;
	}
	if(f==1)
	{
		long long h=a[1]-a[0];
		cout<<1+m/h;
		return 0;
	} 
	for(i=1;i<n;i++)
	{
		int t=m;
		for(j=i-1;j>=0;j--)
		{
			t=t-a[i]+a[j];	
			if(t<0)
			{
				ans=max(ans,i-j);
				break;	
			}
			ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	return 0;
} 
