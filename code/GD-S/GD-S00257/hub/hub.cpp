#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,fa[2000010],deep[2000010];
int e[2000010],ne[2000010],h[2000010],idx,ans=0x3f3f3f3f3f;
void add(int a,int b)
{
	e[++idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
}
void dfs(int x,int faa)
{
	fa[x]=faa;
	deep[x]=deep[faa]+1;
	for(int i=h[x];i;i=ne[i])
	{
		int j=e[i];
		if(j==faa) return;
		dfs(j,x);
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if()
			{
//				ans=min(ans,(int)ceil(lca(i,j)/2.0)+deep[i]-1+deep[j]-1);
			}
		}
	}
}
int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
