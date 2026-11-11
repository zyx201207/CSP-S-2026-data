#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=5e5+10;
bool Mst;
int a[N],pos[N];
map<int,int>ch[N];int id,col[N],pre[N],ed[N];
int ans[N],siz[N];
bool Med;
void dfs(int x)
{
	siz[x]=ed[x];
	for(auto i:ch[x])
	{
		int y=i.second;
		dfs(y);
		siz[x]+=siz[y];
	}
	ans[col[x]]+=siz[x];
}
signed main()
{
//	cerr<<(&Med-&Mst)/1048576.0<<'\n';
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int p=0;
	for(int i=n;i>=1;i--)
	{
		if(pre[a[i]])
		{
			p=pos[pre[a[i]]];
		}
		else
		{
			if(!ch[p][a[i]])ch[p][a[i]]=++id,col[id]=a[i];
			p=ch[p][a[i]];
		}
		ed[p]++;pos[i]=p;pre[a[i]]=i;
	}
	dfs(0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<(i==m?"\n":" ");
	return 0;
}
