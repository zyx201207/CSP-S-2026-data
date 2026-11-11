#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 2e5+10;
long long n,k[maxn],m,ans[maxn],maxx;
bool vis[maxn];
void dfs(int x)
{
	if(x == m+1)
	{
		long long s = ans[1];
		for(int i = 2;i<=m;i++)
			s&=ans[i];
		maxx = max(maxx,s);
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		if(vis[i]||k[i]<=ans[x-1]) continue;
		vis[i] = 1;
		ans[x] = k[i];
		dfs(x+1);
		vis[i] = 0;
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>>m;
	for(int i = 1;i<=n;i++) cin >> k[i];
	sort(k+1,k+n+1);
	dfs(1);
	cout << maxx;
	return 0;
}
