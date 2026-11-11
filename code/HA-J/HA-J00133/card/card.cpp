#include<bits/stdc++.h>
using namespace std;
int s[5000005],t[5000005],sum[5000005];
int main()
{ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		t[i]=s[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[j]==0) continue;
			for(int l=j+1;l<=n;l++)
			{
				if(s[j]==s[l])
				{
					for(int u=j;u<l;u++)
					{
						s[u]=0;
					}
					break;
				}
			}
		}
		for(int o=i;o<=n;o++)
		{
			if(s[o]!=0) sum[s[o]]++;
		}
		for(int p=1;p<=n;p++)
		{
			s[p]=t[p];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}

