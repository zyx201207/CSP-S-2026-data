#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=5e5+15;
int n,m,a[N],b[N],hd[N],cnt,siz[N],ans[N];
struct T{ int to,nxt;}e[N*2];
void adde(int x,int y){ e[++cnt]={y,hd[x]},hd[x]=cnt;}
void dfs(int x)
{
	siz[x]=1;
	for(int i=hd[x];i;i=e[i].nxt) dfs(e[i].to),siz[x]+=siz[e[i].to];
	if(x<=n) ans[a[x]]+=siz[x];
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>0;i--)
	{
		if(b[a[i]]==0) b[a[i]]=i;
		adde(b[a[i]]+1,i);
	}
	dfs(n+1);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

