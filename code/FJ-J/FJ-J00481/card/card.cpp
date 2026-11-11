#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],t[300010],nex[500010],f[500010],ans[300010];
struct Node
{
	int nex,x;
}cnt[500010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0); 
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=n;i>=1;i--)
	{
		if (!t[a[i]]) t[a[i]]=nex[i]=i;
		else nex[i]=t[a[i]];
	}
	for (int i=n;i>=1;i--)
	{
		if (nex[i]==i)
		{
			cnt[i]={i+1,a[i]};
		}
		else
		{
			cnt[i]={nex[i],-1};
		}
	}
	for (int i=1;i<=n;i++)
	{
		f[i]+=1;
		f[cnt[i].nex]+=f[i];
		ans[cnt[i].x]+=f[i];
	}
	for (int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}

