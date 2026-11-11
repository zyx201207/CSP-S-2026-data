#include<bits/stdc++.h>
using namespace std;
int box[300005];
int a[500005];

int main()
{

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		bool vis[200005]={};
		for(int j=i;j<=n;j++)
		{
			vis[j]=1;
			for(int k=i;k<j;k++)
			{
				if((a[k]==a[j])&&vis[k])
				{
					for(int p=k;p<j;p++) vis[p]=0;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++) if(vis[j]) box[a[j]]++;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",box[i]);
	}
	return 0;
}

