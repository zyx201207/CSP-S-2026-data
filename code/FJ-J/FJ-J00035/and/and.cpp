#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int a[200005];
void dfs(int k,int num,int num2)
{
	if(num==m)
	{
		ans=max(ans,num2);
		return;
	}
	for(int i=k+1;i<=n;i++)
	{
		dfs(i,num+1,(num2&a[i]));
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
	}
	else
	{
		if(m==1)
		{
			ans=-100;
			for(int i=1;i<=n;i++)
			{
				ans=max(ans,a[i]);
			}
			cout<<ans;
		}
		else
		{
			for(int i=1;i<=n-m;i++)
			{
				dfs(i,1,a[i]);
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
