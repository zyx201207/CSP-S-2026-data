#include<bits/stdc++.h>
using namespace std;
int s[1000000],d[1000000];
map<int,bool>b;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=0;
		}
		for(int i=k;i<=n;i++)
		{
			if(b[s[i]]==0)
			{
				b[s[i]]=1;
			}
			else
			{
				for(int j=i-1;j>=1;j--)
				{
					if(s[j]==s[i])
					{
						break;
					}
					b[s[j]]=0;
				}
			}
		}
		for(int l=1;l<=m;l++)
		{
			if(b[l]==1)
			{
				d[l]++;
			}
		}
	}
	for(int l=1;l<=m;l++)
	{
		cout<<d[l]<<" ";
	}
	return 0;
}