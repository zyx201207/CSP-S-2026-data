#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
vector<int> edge[N];
int bk[N];
int n,m,ans,mn;
void dfs(int u,int fa,int d)
{
	if(bk[u]) mn=min(mn,d);
	if(d>=mn) return;
	for(int v:edge[u])
		if(v!=fa) dfs(v,u,d+1);
}
void bs(int l)
{
	if(l==n+1)
	{
		int c=0,k=0;
		for(int i=1;i<=n;i++)
			if(bk[i])
			{
				k++;
				int fg=0;
				for(int j:edge[i])
					fg|=bk[j];
				if(!fg) c++;
			}
		if(c<=2&&k==m)
		{
			int res=0;
			for(int i=1;i<=n;i++)
			{
				//~ if(bk[i]) cout<<i<<" ";
				mn=2e9;
				dfs(i,0,0);
				res=max(res,mn);
			}
			//~ cout<<endl;
			ans=min(ans,res);
		}
		return;
	}
	bk[l]=1;
	bs(l+1);
	bk[l]=0;
	bs(l+1);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int ci,T;
	cin>>ci>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v),edge[v].push_back(u);
		}
		ans=2e9;
		if(n<=20)
		{
			bs(1);
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
