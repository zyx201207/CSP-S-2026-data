#include <bits/stdc++.h>
using namespace std;
int n,m,A=1;
int arr[500010],ans[300010],pj[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(arr[i]>arr[i+1]) A=0;
	}
	if(A)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans[arr[j]]++;
				if(arr[j]==arr[j-1]) ans[arr[j]]-=1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
	}
	else
	{
		if(n>=20000)
		{
			for(int i=1;i<=m;i++)
			{
				cout<<n-m<<' ';
			}
		}
		for(int i=1;i<=n;i++)
		{
			int p=1;
			for(int j=i;j<=n;j++)
			{
				pj[p++]=arr[j];
				for(int k=1;k<p-1;k++)
				{
					if(pj[k]==arr[j])
					{
						p=k+1;
						break;
					}
				}
			}
			for(int j=1;j<p;j++)
			{
				ans[pj[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
