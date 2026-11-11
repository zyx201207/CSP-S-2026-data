#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
const int N = 35;
bool X[N];
bool vis[N];
lnt n,k,ans=0,anstrue,maxu[N],t,c;
lnt uv[N][N];
vector<int> s[N];
void build(int u,int st,int l)
{
	vis[u]=1;
	uv[st][u]=l;
	for(auto v : s[u])
	if(!vis[v])build(v,st,l+1);
	return;
}
void dfst(int u)
{
	vis[u] = 1;
	for(auto v : s[u])
	if(!vis[v])dfst(v);
	return;
}
bool check()
{
	memset(vis,0,sizeof(vis));
	int tot = 0;
	for(int i = 1; i<= n; i++)
	if(!vis[i]){dfst(i);tot++;}
	return tot<=2;
}
void dfs(int l,int p)
{
	if(n-l+1+p<k)return;
	if(l == n + 1 && p== k)
	{
		memset(maxu,0x3f,sizeof(maxu));
		if(!check())return;
		ans = 0;
		for(int i = 1; i <= n; i++)
		if(X[i])for(int j =1;j<=n;j++)maxu[j] = min(uv[i][j],maxu[j]);
		for(int i = 1; i<=n;i++)ans=max(maxu[i],ans);
		anstrue = min(ans , anstrue);
		return;
	}
	if(p<k)
	{
	X[l]=1;
	dfs(l+1,p+1);
	}
	X[l]=0;
	dfs(l+1,p);
}
void solve()
{
   cin >> n >> k;
   ans = 0;anstrue = 0x3f;
   for(int i = 1; i<=n;i++)s[i].clear();
   for(int i = 1; i<n ;i++)
   {
   	int a,b;
   	cin >> a>>b;
   	s[a].push_back(b);
   	s[b].push_back(a);
   }
   for(int i = 1; i<= n; i++)
   {
   	memset(vis,0,sizeof(vis));
   	build(i,i,0);
   }
   dfs(1,0);
   cout << anstrue << "\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
cin >> c>>t;
   while(t--)solve();
return 0;
} 
