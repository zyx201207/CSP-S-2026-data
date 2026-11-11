#include<bits/stdc++.h>
using namespace std;
int a[500005]={0};
int ans2[200005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		int tong[m+5]={0};
		for(int j=1;j<=n;j++)
		{
			q.push(a[j]);
			if(tong[a[j]]==0)
			{
				tong[a[j]]++;
			}
			else
			{
				int f=0;
				while(f<2 && !q.empty())
				{
					int p=q.front();
					if(p==a[j])
					{
						f++;
					}
					else
					{
						tong[p]=0;
					}
					q.pop();
				}
				q.push(a[j]);
			}
		}
		
		for(int j=1;j<=m;j++)
		{
			ans2[j]+=tong[a[j]];
		}
		
	}
	ans2[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<ans2[i]<<" ";
	}
	return 0;
}
