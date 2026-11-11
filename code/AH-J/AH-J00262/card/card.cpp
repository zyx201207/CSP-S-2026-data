#include<bits/stdc++.h>
using namespace std;
int a[500001],ans[300001],card_1[500001];
int main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		
		for(int j=i;j<=n;j++)
		{
			card_1[cnt]=a[j];
			for(int k=cnt-1;k>=i;k--)
			{
				if(card_1[cnt]==card_1[k])
				{
					cnt=1;
					for(int l=k;l<=cnt-1;l++) card_1[l]=0;
				}
				break;
			}
			
			cnt++;
		}
		
		for(int j=i;j<=cnt-1;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(card_1[j]==k)
				ans[k]++;
			}
		}
		for(int j=1;j<=n;j++) card_1[j]=0;
		
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
	}
}
