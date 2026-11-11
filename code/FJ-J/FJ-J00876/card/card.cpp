#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2005];
int bz[2005];
int flag[2005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bz[a[i]]=1;
	}
	int idx=1;
	int i=1;
	int l[3005];
	while(i<=m)
	{
		int cnt=0;
		if(bz[idx]!=0)
		{
			l[i]=idx;
			i++;
		}
		idx++;	
	}
	int k[2005];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2005;j++)
		{
			k[j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			k[j]=a[j];
		}
		for(int o=i;o<=n;o++)
		{
			for(int j=1;j<=m;j++)//当前在第o张牌 
			{
				int bz=0;
				for(int y=i;y<=n;y++)
				{
					if(k[i]==l[j])
					{
						bz=1;
					}
				}
				if(bz==0)
				{
					for(int y=i;y<=n;y++)
					{
						if(y==n)
						{
							k[y]==k[1];
						}
						k[y]=k[y+1];
					}
				}
				else
				{
					for(int y=i;y<=n;y++)
					{
						if(k[y]==l[j])
						{
							for(int p=y;p<=n;p++)
							{
								k[p]=0;
							}
						}
					}
					for(int y=i;y<=n;y++)
					{
						if(y==n)
						{
							k[y]==k[1];
						}
						k[y]=k[y+1];
					}
				}
			}
		} 
		for(int j=1;j<=n;j++)
		{
			if(k[j]!=0)
			{
				flag[k[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<flag[i]<<" "; 
	}
	return 0;
}
