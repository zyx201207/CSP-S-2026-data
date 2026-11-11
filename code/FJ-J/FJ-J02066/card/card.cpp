#include<bits/stdc++.h>
using namespace std;
int n,m,l=1;
int card[200200],num[200020],place[200200],all[200020];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	for(int u=1;u<=n;u++)
	{
	for(int i=u;i<=n;i++)
		{
			if(num[card[i]]<1)
			{
				num[card[i]]++;
				place[card[i]]=i;
			}
			else
			{
				for(int j=place[card[i]];j<i;j++)
				{
					num[card[j]]--;
					place[card[j]]=1;
				}
				num[card[i]]++;
				place[card[i]]=i;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(num[j]>0)
			{
				all[j]++;
			}
		}
		for(int j=1;j<=m;j++)
		{
			num[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<all[i]<<" ";
	}
	return 0;
}
