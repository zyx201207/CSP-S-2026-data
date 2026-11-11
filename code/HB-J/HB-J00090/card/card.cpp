#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
int p[500005],hd=-1,ta=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int book[300005]={};
		for(int j=i+1;j<=n;j++)
		{
			if(book[a[j]]==0)
			{
				p[++hd]=a[j];
				book[a[j]]=1;
			}
			else
			{
				for(int k=ta;k<=hd;k++)
				{
					if(p[k]==a[j])
					{
						hd=k-1;
						for(int l=ta;l<=hd;l++)
						{
							book[p[l]]=0;
						}
						break;
					}
				}
				p[++hd]=a[j];
				book[a[j]]=1;
			}
		}
		for(int k=ta;k<=hd;k++)
		{
			ans[p[k]]++;
		}
		hd=-1;
		ta=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
