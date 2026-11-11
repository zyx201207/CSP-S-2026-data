#include <bits/stdc++.h>
using namespace std;
int n,m,a[500006];
int b[500006];
int ans[5000006],pai[5000006];
int chang=1,cnt;
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
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				pai[chang]=a[j];
				chang++;
				cnt=chang;
				b[a[j]]++;
				
			}
			else
			{
				for(int k=cnt-1;k>=1;k--)
				{
					if(pai[k]!=a[j])
					{	
						pai[k]=0;
						chang-=1;
						b[pai[k]]=0;
						
					}
					if(pai[k]==a[j])
					{
						cnt=chang;
						break;
					}
				}
				
			}
		}
		
		for(int k=1;k<=chang;k++)
		{
			ans[pai[k]]+=1;
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

