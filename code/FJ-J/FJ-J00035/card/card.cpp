#include<bits/stdc++.h>
using namespace std;
int v[300005];
int a[500005];
int ans[300005];
int n,m;
void dfs(int s)
{
	for(int i=s;i<=n;i++)
	{
		if(v[a[i]]==0)
		{
			v[a[i]]=i;
		}
		else
		{
			for(int j=v[a[i]];j<=i;j++)
			{
				v[a[j]]=0;
			}
			v[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(v[i]!=0)
		{
			ans[i]++;
		}
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		dfs(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
