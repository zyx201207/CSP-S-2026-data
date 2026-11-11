#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=21;
int c,t,n,k,r0,r1;
basic_string<int> G[N];
int dep[N],rt=1,mxdep=0,mxd[N],f[N][M];
set<int> s,S;
void dfs1(int u,int fa=0)
{
	mxd[u]=u;dep[u]=dep[fa]+1,f[u][0]=fa;
	mxdep=max(mxdep,dep[u]);
	for(int v:G[u])
		if(v!=fa) dfs1(v,u),(dep[mxd[v]]>dep[mxd[u]])?mxd[u]=mxd[v]:0;
}
void dfs2(int u,int fa=0)
{
	f[u][0]=fa;
	for(int i=1;i<M;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int v:G[u])
		if(v!=fa) dfs2(v,u); 
}
int kkthfa(int u,int kk)
{
	for(int i=M-1;i>=0;i--)
	{
		if((1<<i)<=kk)
			u=f[u][i],kk-=(1<<i);
	}
	return u;
}
bool check(int mm)
{
//	cout<<"checkmm"<<mm<<'\n';
	s.clear();
	int mxdd=0;
	for(int i=1,x;i<=n;i++)
	{
		x=kkthfa(mxd[i],mm);
		if(x==0) continue;
		s.insert(x),mxdd=max(mxdd,dep[x]);
//		cout<<x<<'\n';
	}
	int ss=s.size();
	while(1)
	{
		if(ss>k) return false;
		if(s.size()<=2) return true;
		for(int u:s)
		{
			if(dep[u]==mxdd)
				S.insert(u);
		}
		for(int u:S)
		{
			s.erase(u);
			if(s.find(f[u][0])==s.end())
				ss++,s.insert(f[u][0]);
		}
		S.clear();
		mxdd--;
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,G[u]+=v,G[v]+=u;
	if(k==n)
	{
		cout<<0<<'\n';
		return;
	}
	if(c>=13&&c<=14)
	{
		int m=n/2,mm=(m+1)/2,kk;
		if(k>=m)
		{
			cout<<1<<'\n';
			return;
		}
		if(m&1) kk=(k+1)/2;
		else kk/=2;
		cout<<(mm+2-kk+1)/2<<'\n';
		return;
	}
	dfs1(1);
	dfs1(r0=mxd[1]);
	r1=mxd[r0];
	rt=r1;
	for(int i=1;i<=(dep[r1]-dep[r0])/2;i++)
		rt=f[rt][0];
	dfs1(rt);
	dfs2(rt);
	int l=1,r=mxdep,ans=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
		G[i].clear();
	mxdep=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/

