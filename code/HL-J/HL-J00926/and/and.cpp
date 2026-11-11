#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f[200005][40],cf[40],cnt,ans,vis[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cf[0]=1;
	for(int i=1;i<=30;i++)
	{
		cf[i]=cf[i-1]*2;
	}
	for(int i=1;i<=n;i++)
	{
		int x,sum=0;
		scanf("%d",&x);
		while(x)
		{
			f[i][++sum]=x%2;
			x/=2;
		}
		cnt=max(cnt,sum);
	}
	for(int i=cnt;i;i--)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			if(f[j][i]) sum++;
		}
		if(sum>=m)
		{
			ans+=cf[i-1];
			for(int j=1;j<=n;j++)
			{
				if(vis[j]) continue;
				if(!f[j][i]) vis[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}