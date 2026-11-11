#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000010;
int CID,T,n,f[N],g[N],nxt[N];
ll d,x[N],ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>CID>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		}
		ans=0;
		if(CID==13||CID==14)
		{
			int p;
			for(int i=1;i<=n;i++)
			{
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d)
				{
					p=i;
					break;
				}
			}
			for(int i=1;i<p;i++)
			{
				ans+=max(0,nxt[nxt[i]-1]-max(nxt[i],nxt[nxt[i]-2]));
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=n;i>=1;i--)
		{
			f[i]=0,g[i]=1;
			for(int j=i-1;j>=1;j--)
			{
				if(nxt[j]==j) break;
				int x=min(nxt[j],i);
				f[j]=f[x]+1,g[j]=g[x];
				if(x-1>j&&f[x-1]+1==f[j]) g[j]+=g[x-1];
				if(x-2>j&&f[x-2]+1==f[j]) g[j]+=g[x-2];
				g[j]=min(g[j],3);
				if(g[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

*/
