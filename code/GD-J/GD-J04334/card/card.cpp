#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[500005];
map <int,int> mp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int f=1;f<=n;f++)
	{
		mp.clear();
		for(int i=f;i<=n;i++)
		{
			if(mp[a[i]]==0) mp[a[i]]=1;
			else 
			{
				for(int j=i-1;j>=1;j--)
				{
					if(a[j]==a[i]) break;
					mp[a[j]]=0;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(mp[i]!=0)
			ans[i]++;
		}
	}
	for(int i=1;i<=m;i++) 
	cout<<ans[i]<<" ";
	return 0;
} 
