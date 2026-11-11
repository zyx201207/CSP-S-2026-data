#include <bits/stdc++.h>
using namespace std;
int a[500005],s[500005],id[500005],ss[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=l;i<=n;i++)
		{
			s[a[i]]++;
			if(s[a[i]]==2)
			{
				for(int j=id[a[i]];j<i;j++)
				{
					s[a[j]]--;
				}
			}
			id[a[i]]=i;
		}
		for(int k=1;k<=m;k++)
		{
			if(s[k]==1)
			{
				ss[k]++;
			}
			s[k]=0;
			id[k]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ss[i]<<' ';
	}
	return 0;
}
