#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[10005],a[10005],pos[10005],ans[10005];
bool vis[10005];
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
		for(int k=i;k<=n;k++)
		{
			if(pos[a[k]])
			{
				d[pos[a[k]]]++;
				d[k]--;
				for(int j=pos[a[k]];j<k;j++)
				{
					pos[a[j]]=0;
					vis[j]=0;
				}
			}
			pos[a[k]]=k;
		}
	}
	for(int i=1;i<=n;i++)
	{
		d[i]+=d[i-1];
		ans[a[i]]+=d[i];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
