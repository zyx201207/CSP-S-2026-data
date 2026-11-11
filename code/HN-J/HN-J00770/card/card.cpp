#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[200001],s[100001],p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		s[i]==0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[k]==a[j])
				{
					j=k-1;
					p=1;
					break;
				}
			}
			if(p==0)
			{
				s[a[j]]++;
			}
			p=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<' ';
	}
	return 0;
}
