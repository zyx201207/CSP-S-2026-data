#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],x,ans;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+m-1])
		{
			x=a[i];
			break;
		}
	}
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	else
	{
		ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans&=a[i];
		}
	}
	if(ans<x)
	{
		ans=x;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
