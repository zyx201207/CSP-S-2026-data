#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],b[500001],mp[300001],l=1,ans[300001],fla;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])fla=1;
	}
	for(int k=1;k<=n;k++)
	{
		memset(b,0,sizeof(b));
		memset(mp,0,sizeof(mp));
		l=1;
		b[1]=a[k];	
		mp[a[k]]=1;
		for(int i=k+1;i<=n;i++)
		{
			if(mp[a[i]])
			{
				int gr=mp[a[i]];
				for(int j=mp[a[i]];j<=l;j++)
				{
					mp[b[j]]=0;
					b[j]=0;
				}
				l=gr;
			}
			mp[a[i]]=l+1;
			b[l+1]=a[i];
			l++;
		}
		for(int i=1;i<=l;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i]==j)
				{
					ans[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
1 2 3


1 2 3
*/
