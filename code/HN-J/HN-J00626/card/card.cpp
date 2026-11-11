#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],cnt[N],lst[N],m;
vector<int>g[N];
void dfs(int x)
{
	for(auto i:g[x])
	{
		dfs(i);
		cnt[x]+=cnt[i];
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++)g[a[lst[i]+1]].push_back(i);
	dfs(a[n]); 
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}

