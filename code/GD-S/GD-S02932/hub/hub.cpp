#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define inr(L,R,l,r) (l<=L and R<=r)
#define ofr(L,R,l,r) (L>r or l>R)
#define re return
#define ll long long
#define ull unsigned long long
#define ioo cin.tie(0)->sync_with_stdio(0);cout.tie(0)->sync_with_stdio(0);
using namespace std;
const int maxn=1e6+115;
vector<int> G[maxn];
int U[maxn],V[maxn];
vector<int> S[5];
int maxdep[maxn],dep[maxn];
int K;
int bu,bv;
void dfs(int u,int fa)
{
	maxdep[u]=dep[u]=dep[fa]+1;
	for(auto v:G[u])
	{
		if(v==fa) continue;
		if((u==bu and v==bv)or(u==bv and v==bu)) continue;
		dfs(v,u);
		maxdep[u]=max(maxdep[u],maxdep[v]);
	}
}
void dfsS(int u,int fa,int top)
{
	S[top].push_back(u);
	for(auto v:G[u])
	{
		if(v==fa) continue;
		if((u==bu and v==bv)or(u==bv and v==bu)) continue;
		dfsS(v,u,top);
	}
}
int query(int u,int fa)
{
	if(maxdep[u]-dep[u]<=K) re 0;
	int ans=1;
	for(auto v:G[u])
	{
		if(v==fa) continue;
		if((u==bu and v==bv)or(u==bv and v==bu)) continue;
		ans+=query(v,u);
	}
	re ans;
}
int n,k;
void solve()
{
	cin>>n>>k;
	rep(i,1,n) G[i].clear();
	rep(i,1,n-1)
	{
		cin>>U[i]>>V[i];
		G[U[i]].push_back(V[i]);
		G[V[i]].push_back(U[i]);
	}
	U[n]=V[n]=0;
	ll ans=0;
	rep(i,1,n-1)
	{
		bu=U[i];
		bv=V[i];
		S[1].clear();
		S[2].clear();
		int L=0,R=n+1,M;
		dfsS(bu,0,1);
		dfsS(bv,0,2);
		while(L+1<R)
		{
			M=L+R>>1;
			int x=n+1,y=n+1;
			K=M;
			for(auto u:S[1])
			{
				dfs(u,0);
				x=min(x,query(u,0));
			}
			for(auto u:S[2])
			{
				dfs(u,0);
				y=min(y,query(u,0));
			}
			if(x+y>k) L=M;
			else R=M;
		}
		ans=max(ans,(ll)R);
	}
	int L=0,R=n+1,M;
	bu=bv=0;
	while(L+1<R)
	{
		M=L+R>>1;
		int x=n+1;
		K=M;
		rep(u,1,n)
		{
			dfs(u,0);
			x=min(x,query(u,0));
		}
		if(x>k) L=M;
		else R=M;
	}
	ans=max(ans,(ll)R);
	cout<<ans<<'\n';
}
int main()
{
	ioo;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
}
