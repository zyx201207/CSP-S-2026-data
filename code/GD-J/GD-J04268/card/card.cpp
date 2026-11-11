#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10,M=3e5+10;
int n,m,a[N],cnt[N],gv[N],nxt[N],ans[M],sum[M],vis[M];
vector<int> g[M];
bool lst[N]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],g[a[i]].push_back(i),sum[a[i]]++;
	for(int i=1;i<=m;i++)
		for(int j=0;j<g[i].size()-1;j++)
			nxt[g[i][j]]=g[i][j+1];
	for(int i=n;i>=1;i--) cnt[i]++,gv[i]=((nxt[i]==0)?i+1:nxt[i]),lst[i]=(nxt[i]==0);
	for(int i=1;i<=n;i++)
	{
		cnt[gv[i]]+=cnt[i];
		if(lst[i]) ans[a[i]]+=cnt[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
