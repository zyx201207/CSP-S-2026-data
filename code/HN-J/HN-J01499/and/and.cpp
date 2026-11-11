#include<bits/stdc++.h>
using namespace std;
int a[3000010];
int use[3000010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=2147483647;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		use[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		ans = ans&a[i];
	}
	if(m==1)
	{
		ans=a[1];
	}
	cout<<ans;
	return 0;
}
