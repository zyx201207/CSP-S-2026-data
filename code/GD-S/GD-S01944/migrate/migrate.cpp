#include<bits/stdc++.h>
using namespace std;
#define rig register int
#define cit const int&
#define void inline void
int c,t,n,d,x[2000005],ans,now,res;
void dfs(cit dep,cit to,cit s)
{
	if(dep==to)
	{
		if(s<now) ans=0,now=s;
		ans++; return;
	}
	for(rig i=dep+1;i<=to;i++)
	{
		if(x[i]-x[dep]>d) break;
		dfs(i,to,s+1);
	}
}
void solve()
{
	cin>>n>>d; res=0;
	for(rig i=1;i<=n;i++) cin>>x[i];
	sort(x+1,x+1+n);
	for(rig i=1;i<n;i++)
		for(rig j=i+1;j<=n;j++)
			now=INT_MAX,ans=0,dfs(i,j,1),res+=ans==2;
	cout<<res<<'\n';
}
main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
}
