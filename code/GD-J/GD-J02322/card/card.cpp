#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],fid[300005];
bool f,vis[300005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]=max(cnt[a[i]],i);
	}
	for(int i=n;i>=1;i--)
	{
		if(!vis[a[i]])
		{
			cnt[a[i]]=max(cnt[a[i]],i);
			fid[a[i]]=i;
			vis[a[i]]=1;
		}
		else
		{
			for(int j=i+1;a[j]!=a[i];j++)
			{
				cnt[a[j]]=j;
				vis[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<' ';
	return 0;
}
