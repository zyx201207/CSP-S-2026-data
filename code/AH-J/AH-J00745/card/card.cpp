#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],last[500010];
int f[500010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(f[a[i]])
		{
			last[i]=f[a[i]];
		}
		else
		{
			f[a[i]]=i;
		}
	}
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;)
		{
			if(last[j])
			{
				j=last[j];
			}
			else
			{
				if(!last[i]&&j!=i)
				{
					f[a[j]]++;
				}
				f[a[j]]++;
				j++;
			}
		}
		if(!last[i])
		{
			i++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<' ';
	}
	return 0;
}
