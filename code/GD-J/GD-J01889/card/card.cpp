#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vector<int>ve;
		for(int j=i;j<=n;j++)
		{
			if(find(ve.begin(),ve.end(),a[j])!=ve.end())
			{
				while(ve.back()!=a[j])ve.pop_back();
			}
			else
			{
				ve.push_back(a[j]);
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(find(ve.begin(),ve.end(),j)!=ve.end())cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
