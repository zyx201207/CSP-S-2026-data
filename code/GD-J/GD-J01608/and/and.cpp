#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	}
	else
	{
		sort(a+1,a+1+n);
		ans=a[m];
	}
	cout<<ans;
	return 0;
}

