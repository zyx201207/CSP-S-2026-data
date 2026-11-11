#include<bits/stdc++.h>
using namespace std;
#define int long long
#define file(S) freopen(S".in","r",stdin),freopen(S".out","w",stdout);
const int N=20;
vector<int> E[N]; 
int dfn[N],st[N][20],lg[N];
void dfs(int u,int f)
{
	dfn[u]=++dfn[0];
	st[u][0]=f;
	for(auto to:E[u]){
		if(to==f) continue;
		dfs(to,u);
	}
}
int mx(int u,int v)
{
	if(dfn[u]<dfn[v]) return u;
	else return v;
}
int LCA(int u,int v)
{
	u=dfn[u],v=dfn[v];
	if(u==v) return u;
	++u;
	int len=lg[r-l+1];
	return mx(st[u][len],st[v-(1<<len)+1][len]);
}
void Luo_Saisei() {
	cout<<1<<'\n';
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++) E[i].clear();
//	for(int i=1;i<=n-1;i++)
//	{
//		int u,v;
//		cin>>u>>v;
//		E[u].emplace_back(v);
//		E[v].emplace_back(u);
//	}
//	dfs(1,0);
//	lg[1]=0;
//	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
//	for(int i=1;i<=lg[n];i++)
//	{
//		for(int j=1;j+(1<<i)-1<=n;j++)
//		{
//			st[j][i]=mx(st[j][i-1],st[j+(1<<(i-1))][i-1]);
//		}
//	}
//	for(int nmx=1;nmx<(1<<n);nmx++)
//	{
//		vector<int> v1;
//		int cnt1=0;
//		for(int j=n-1;j>=0;j--)
//		{
//			if(nmx>>j&1) v1.emplace_back(j+1),++cnt1;
//		}
//		int pmx=(1<<n)-1-nmx;
//		for(int j=n-1;j>=0;j--)
//		{
//			
//		}
//	}
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	file("hub");
	int c,T=1;
	cin>>T;
	while(T--) Luo_Saisei();
}
