#include<bits/stdc++.h>
using namespace std;

long long n,m,a[100005],vis[100005],ans[10005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)	vis[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(vis[j]!=0)	ans[vis[j]]++;
		}
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
