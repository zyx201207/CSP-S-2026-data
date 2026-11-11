#include <bits/stdc++.h> 
using namespace std;
int n,m,a[500005],cnt[300005];
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
		int vis[300005],idx[300005],xb=0;
		for(int j=1;j<=m+1;j++) vis[j]=0;
		vector<int> cd;
		for(int j=i;j<=n;j++) 
		{
			if(vis[a[j]]) 
			{
				for(int k=idx[a[j]]+1;k<cd.size();k++) 
				{
					idx[cd[k]]=0;vis[cd[k]]=0;
					xb--;
				}
				cd.erase(cd.begin()+idx[a[j]],cd.end());
				cd.push_back(a[j]);
			}
			else 
			{
				cd.push_back(a[j]);
				vis[a[j]]=1;
				idx[a[j]]=xb++;
			}
		}
		for(int j=0;j<cd.size();j++) cnt[cd[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
