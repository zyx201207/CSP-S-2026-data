#include <bits/stdc++.h>
#define int long long
#define For(i,n) for(int i=1;i<=n;i++)
#define Fors(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int N=2e6+5,inf=1e18;
int c,t,n,d,x[N],u,v,ans0,cnt0;

void DFS(int now,int dis)
{
	if(dis>ans0) return;
	if(now==v)
	{
		if(dis<ans0) ans0=dis,cnt0=1;
		else if(dis==ans0) cnt0++;
		return;
	}
	for(int nxt=now+1;nxt<=n and x[nxt]-x[now]<=d;nxt++)
	{
		DFS(nxt,dis+1);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		For(i,n) cin>>x[i];
		For(i,n) Fors(j,i+1,n)
		{
			u=i;
			v=j;
			ans0=inf;
			cnt0=0;
			DFS(i,0);
			if(cnt0==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
