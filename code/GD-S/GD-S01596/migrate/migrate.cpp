#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000010],nxt[2000010],s[2000010],f[2000010],g[2000010],s2[2000010];
void solve()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i],g[i]=0;
	x[n+1]=4e18;
	for(int i=1;i<=n;i++) nxt[i]=upper_bound(x+1,x+n+2,x[i]+d)-x-1;
	for(int i=n;i;i--)
	{
		if(x[i-1]+d>=x[nxt[i]]) f[i]=1;
		else f[i]=f[nxt[i]]+1;
	}
	for(int i=1;i<=n;i++)
	{
		g[i]++;
		if(i>1&&x[i-1]+d>=x[nxt[i]]) continue;
		
		g[nxt[i]]+=g[i];
	}
	for(int i=1;i<=n;i++) s[i]=s[i-1]+f[i],s2[i]=s2[i-1]+f[nxt[i]];
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		int r=upper_bound(x+1,x+n+2,x[i-1]+d)-x-1,l=(i==2?i+1:upper_bound(x+1,x+n+2,x[i-2]+d)-x);
		l=max(l,i+1);
		if(l>r) continue;
		ans+=(g[i]-1)*(s[r]-s[l-1]);
	}
	cout<<ans-1<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
}
