#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[500010],lst[300010],c[500010],p,ans[300010];
bool flaga=1;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1&&a[i-1]<=a[i])
		{
			flaga=0;
		}
	}
	if(flaga)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			{
				cout<<i<<" ";
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(lst,0,sizeof(lst));
		memset(c,0,sizeof(c));
		p=0;
		for(int j=i;j<=n;j++)
		{
			if(lst[a[j]]!=0)
			{
				for(int k=lst[a[j]]+1;k<=p;k++)
				{
					lst[c[k]]=0;
					c[k]=0;
				}
				p=lst[a[j]];
			}
			else
			{
				p++;
				c[p]=a[j];
				lst[a[j]]=p;
			}
		}
		for(int j=1;j<=p;j++)
		{
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}

	return 0;
}
