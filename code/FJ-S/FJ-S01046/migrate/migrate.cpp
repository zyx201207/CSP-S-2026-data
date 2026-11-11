#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;
int id,n,m,ans,a[N],nxt[N],f[N],g[N];
void bfs(int st)
{
	for(int i=1;i<=n;i++) f[i]=0,g[i]=1e18;
	f[st]=1,g[st]=0;
	queue<int>q;
	q.push(st);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=nxt[x];i>=x+1;i--)
		{
			if(g[i]>g[x]+1) g[i]=g[x]+1,f[i]=f[x],q.push(i);
			else if(g[i]==g[x]+1) f[i]=min(f[i]+f[x],3ll); 
		}
	}
	for(int i=1;i<=n;i++) ans+=(f[i]==2);
	return;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<n&&a[j+1]-a[i]<=m) j++;
		nxt[i]=j;
	}
	if(id==11||id==12)
	{
		m/=(a[2]-a[1]);
		if(m<=1) cout<<0<<"\n";
		else cout<<max(0ll,n-m*2+1)<<"\n";
		return;
	}
	if(n<=300)
	{
		for(int i=1;i<=n;i++) bfs(i);
	}
	else//n^2
	{
		for(int i=1;i<=n;i++)
		{
			int last=i;
			int sum=0;
			for(int j=nxt[i];j<=n;j=nxt[j])
			{
				if(last!=i)
				{
					for(int k=last+1;k<j;k++)
					{
						int cnt=0;
						cnt+=(a[k]-a[last-1]<=m);
						cnt+=(last>2&&a[k]-a[last-2]<=m);
						if(sum+cnt==1) ans++;
					}
					if(a[j]-a[last-1]<=m) sum++;
					if(last>2&&a[j]-a[last-2]<=m) sum++;
					if(sum>1) break;
					if(sum==1) ans++;
				}
				last=j;
				if(nxt[j]==j) break;
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>id>>t;
	while(t--) solve();
	return 0;
}
/*

0 1
8 3
0 1 2 4 8 10 11 13
ans=2

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
ans=16
*/
