#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],an[300010];
int p[300010];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j) p[j]=0;
		for(int j=i;j<=n;++j)
		{
			if(p[a[j]]!=0)
			{
				for(int k=p[a[j]];k<=j;++k)
				{
					p[a[k]]=0;
				}
			}
			p[a[j]]=j;
		}
		for(int j=1;j<=m;++j)
		{
			if(p[j]) an[j]++;
		}
	}
	for(int i=1;i<=m;++i) cout<<an[i]<<" ";
	return 0;
}
