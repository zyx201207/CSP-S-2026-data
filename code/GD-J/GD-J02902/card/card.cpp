#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500005],ans[300005],vis[500005];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=n;k++) vis[k]=0;
			int f=0;
			for(int k=i;k<j;k++)
			{
				if(arr[k]==arr[j]) f=1;
				if(f) vis[k]=1;
			}
			for(int k=i;k<n;k++)
			{
				if(!vis[k]) ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}

