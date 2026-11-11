#include <bits/stdc++.h>
using namespace std;
int n = 0;
int m = 0;
int a[500010] = {};
int b[300010] = {};

int dfs(int x)
{
	int pd[500010] = {};
	if(x>n)
	{
		return 0;
	}
	for(int i=x;i<=n;i++)
	{
		pd[i]=a[i];
		for(int j=i-1;j>=x;j--)
		{
			if(pd[i]==pd[j])
			{
				for(int k=pd[j];k<=pd[i];k++)
				{
					pd[k]=0;
				}
				pd[j]=a[i];
				break;
				//pd[j,i]={};
				
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(pd[j]==i)
			{
				b[i]++;
				break;
			}
		}
	}
	dfs(x+1);
	return 0;
}
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		cout<<b[i];
	}
	return 0;
}
