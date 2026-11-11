#include<bits/stdc++.h>
using namespace std;
vector<int>e[1000006];
int dep[1000006],sn[1000006],fa[1000006],mmx,mxx;
void dfs(int x,int ff)
{
	sn[x]=1;
	dep[x]=dep[ff]+1;
	fa[x]=ff;
	for(auto i:e[x])
	{
		if(i==ff)continue;
		dfs(i,x);
		sn[x]+=sn[i];
	}
}
void dfs2(int x,int mx,int fa)
{
	if(mx>mmx)
	{
		mmx=mx;
		mxx=x;
	}
	for(auto i:e[x])
	{
		if(i==fa)continue;
		dfs2(i,mx+1,x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dep[1]=-1;
		dfs(1,1);
		dfs2(1,0,1);
		int m1=mxx;
		mxx=0,mmx=0;
		dfs2(m1,0,1);
		int m2=mxx;
		if(k==2)
		{
//			cout<<m1<<" "<<m2<<' '<<dep[m1]+dep[m2]+1<<endl;
			cout<<floor((dep[m1]+dep[m2]+1)/3)<<'\n';
		}
	}
}
/*
Luogu uid:919748
//freopen("crystal.in","r",stdin); 
freopen("crystal.in1","r",stdin); 
froepen("crystal.in","r",stdin); 
我要进迷惑行为大赏
膜拜ridewindHE
ridewindHE AK IOI
Oct31==Dec25?
*/
