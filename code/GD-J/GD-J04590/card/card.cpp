#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],ans[200005];
bool vis[200005];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int now;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			now=a[j];
			if(!vis[now])
			{
				vis[now]=1;
				b[j]=now;
			}
			else
			{
				int pos=0;
				for(int k=1;k<=n;k++)
				{
					if(b[k]==a[j])
					{
						if(!pos) pos=k;
					}
				}
				b[pos]=a[j];
			}
		}
		for(int j=1;j<=n;j++)
		{
			ans[b[j]]=i;
			vis[j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
