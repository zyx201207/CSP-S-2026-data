#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int lst[300005];
int vis[500005];
int ans[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		int now=i,cnt=0;
		while(now<=n)
		{
			if(vis[now]) cnt--;
			ans[a[now]]+=(++cnt);
			vis[now]=1;
			now=lst[a[now]]+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
