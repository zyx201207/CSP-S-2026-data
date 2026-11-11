#include<bits/stdc++.h>
using namespace std;
int a[200005];
int f=2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n;i>=n;i--)
	{
		if(log(a[i])==int(log(a[i])))
		{
			f=1;
			if(t-i>=m)
			{
				f=0;
				ans=a[t];
				for(int j=t;j>=t-m+1;j--)
				{
					ans=ans&a[j];
				}
				break;
			}
			else
			{
				t=i-1;
			}
		}
	}
	if(f==1)
	{
		ans=0;
	}
	else if(f==2)
	{
		for(int i=0;i<m;i++)
		{
			ans=ans&a[n-i];
		}
	}
	cout<<ans;
	return 0;
}
