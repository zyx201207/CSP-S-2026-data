#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5;
const int M=3e5;
int n,m,a[N+5],la[M+5],en[M+5],siz[N+5];
vector<int>e[N+5];
void dfs(int now)
{
	siz[now]=1;
	for(int son:e[now])
	{
		dfs(son);
		siz[now]+=siz[son];
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	la[a[n]]=n;en[a[n]]=n;
	for(int i=n-1;i>=1;i--)
	{
		if(la[a[i]]) e[la[a[i]]].push_back(i);
		else e[i+1].push_back(i),en[a[i]]=i;
		la[a[i]]=i;
	}
	dfs(n);
	for(int i=1;i<=m;i++) cout<<siz[en[i]]<<" ";
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;//cin>>_;
	while(_--) solve();
	return 0;
}
// CSP2026-J/S RP++
