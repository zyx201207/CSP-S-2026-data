#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,rt,X,Y,F;
vector<int>e[1000001];
int dep[1000001],f[1000001],mk[1000001],ban[1000001],si[1000001],ff[1000001][21];
void dfs(int x,int fa)
{
	si[x]=1;
	for(int y:e[x]) if(y^fa) dfs(y,x),si[x]+=si[y];
	return;
}
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x]=fa;
	if(dep[x]>dep[X]) X=x;
	for(int y:e[x]) if((y^fa)&&!ban[y]) dfs1(y,x);
	return;
}
void dfs2(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x]=fa;
	if(dep[x]>dep[Y]) Y=x;
	for(int y:e[x]) if((y^fa)&&!ban[y]) dfs2(y,x);
	return;
}
vector<int>ve;
void dfs3(int x,int fa)
{
	ve.push_back(x),ff[x][0]=fa;
	dep[x]=dep[fa]+1,f[x]=fa;
	for(int i=1;i<=20;i++) ff[x][i]=ff[ff[x][i-1]][i-1];
	for(int y:e[x]) if((y^fa)&&!ban[y]) dfs3(y,x);
	return;
}
int jump(int x,int d)
{
	for(int i=20;i>=0;i--) if(ff[x][i]&&dep[ff[x][i]]-1>=d) x=ff[x][i];
	return x;
}
int ck(int md)
{
	for(int i=1;i<=n;i++) mk[i]=0;
	int ans=0;
	X=Y=0;
	ban[rt]=1;
	dfs1(1,0),dfs2(X,0);
	vector<int>v;
	while(Y) v.push_back(Y),Y=f[Y];
	int rr=v[(v.size())/2];
	mk[rr]=1;
	ve.clear(),dfs3(rr,0);
	for(int x:ve)
	{
		int xx=x;
		if(dep[x]-1<=md) continue;
		int tmp=dep[x]-1-md;
		x=jump(x,tmp);
		mk[x]=1;
	}
	ban[rt]=0,ban[F]=1;
	X=Y=0;
	dfs1(rt,0),dfs2(X,0);
	v.clear();
	while(Y) v.push_back(Y),Y=f[Y];
	rr=v[(v.size())/2];
	mk[rr]=1;
	ve.clear(),dfs3(rr,0);
	for(int x:ve)
	{
		if(dep[x]-1<=md) continue;
		int tmp=dep[x]-1-md;
		x=jump(x,tmp);
		mk[x]=1;
	}
	ban[F]=0;
	for(int i=1;i<=n;i++) ans+=mk[i];
	return ans<=k;
}
int tt;
void solve()
{
	tt++;
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1,0);
	X=Y=0,rt=-1;
	dfs1(1,0),dfs2(X,0);
	vector<int>v;
	while(Y) v.push_back(Y),Y=f[Y];
	if(n>4000)
	{
		rt=v[(v.size()+1)/2];
		dfs1(1,0),F=f[rt];
		int l=0,r=n,an=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(ck(mid)) r=mid-1,an=mid;
			else l=mid+1;
		}
		cout<<an<<"\n";
		return;
	}
	int Ans=2e9;
	for(int i=1;i<=n;i++)
	{
		rt=i;
		dfs1(1,0),F=f[rt];
		int l=0,r=n,an=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(ck(mid)) r=mid-1,an=mid;
			else l=mid+1;
		}
		Ans=min(Ans,an);
	}
	cout<<Ans<<"\n";
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t>>t;
	while(t--) solve();
	return 0;
}
