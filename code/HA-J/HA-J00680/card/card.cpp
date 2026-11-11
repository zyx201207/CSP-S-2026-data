#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];	
	}
	int i = 1;
	while(i<=n)
	{		
		for(int j = i;j<=n;j++)
		{
			b[j] = a[j];
			for(int k = i;k<=j;k++)
			{
				if(b[k]==b[j]&&k!=j)
				{
					for(int l = k+1;l<=j;l++)
					{
						b[l] = 0;
					}
					break;
				}
			}
		}
		for(int j = i;j<=n;j++)
		{
			if(b[j]!=0)
				ans[b[j]]++;
		}
		i++;
	}
	for(int j = 1;j<=m;j++)
	{
		cout<<ans[j]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
