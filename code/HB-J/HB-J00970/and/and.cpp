#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans=a[i]&a[i+1];
			a[i+1]=ans;
		}
		cout<<ans;
	}
	if(m==1)
	{
		sort(a,a+n);
		cout<<a[n];
	}
	return 0;
}
