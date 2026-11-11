#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
map<int,int>mp,ans,no;
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
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
			if(!mp[a[j]])
			{
				mp[a[j]]=j;
			}
			else
			{
				for(int k=mp[a[j]];k<j;k++)
				{
					no[k]=1;
					mp[a[k]]=0;
				}
				mp[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(no[j]==0)ans[a[j]]++;
		}
		mp.clear();
		no.clear();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' '; 
	return 0;
}
