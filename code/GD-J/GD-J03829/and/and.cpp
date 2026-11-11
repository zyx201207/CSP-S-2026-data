#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans(-1);
int sz[200005],temp[200005];
bool cmp(int a,int b)
{
	return a > b;
}
void dfs(int id,int num)
{
	if (num == m)
	{
		int sum = temp[1];
		for (int i =2;i <= m;i++)
			sum &= temp[i];
		ans = max(ans,sum);
		return;
	}
	if (id == n+1)
		return;
	dfs(id+1,num);
	temp[num+1] = sz[id];
	dfs(id+1,num+1);
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> sz[i];
	sort(sz+1,sz+n+1,cmp);
	if (m <= 20)
	{
		dfs(1,0);
		cout << ans;
		return 0;
	}
	int tans = sz[1];
	for (int i = 2;i <= m;i++)
		tans &= sz[i];
	cout << tans; 
	return 0;
} 
/*

*/
