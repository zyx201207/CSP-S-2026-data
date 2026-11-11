#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
vector<int> g[5010];
int ret[5010][5010],cnt[5010][5010];
void dfs(int x,int h,int id)
{
	for(int i = 0;i < (int)g[x].size();i++)
	{
		int y = g[x][i];
		if(ret[id][y] > h)
		{
			ret[id][y] = h;
			cnt[id][y] = 1;
		}
		else cnt[id][y]++;
		dfs(y,h + 1,id);
	}
	return;
}
void sol()
{
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		g[i].clear();
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		ret[i][j] = cnt[i][j];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(abs(a[j] - a[i]) <= m)
			g[i].push_back(j);
		}
	}
	for(int i = 1;i <= n;i++)dfs(i,0,i);
	int tot = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(cnt[i][j] == 2)	
			tot++;
		}
	}
	cout << tot << "\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int C,T;
	cin >> C >> T;
	while(T--)sol();
	return 0;
} 
