#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ton[300005];
int num[300005];
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
		memset(ton,0,sizeof(ton));
		for(int j=i;j<=n;j++)
		{
			if(ton[a[j]]==1)
			{
				for(int k=j-1;k>=1;k--)
				{
					if(a[k]==a[j]) break;
					else ton[a[k]]=0;
				}
			}
			ton[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(ton[j]==1)
			{
				num[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
