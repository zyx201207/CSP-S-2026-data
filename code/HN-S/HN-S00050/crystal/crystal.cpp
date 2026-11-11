#include<bits/stdc++.h>
using namespace std;
const int N = 100000050;
long long n,m,a[N],ans = 0,sum = 0,flag[N],cut = 1,s = -1e9;
void dfs(long long x,long long y)
{
	if(y > n) exit(0);
	for(int i = 0;i <= y;i++)
	{
		ans += (x - a[i]);
		sum++;
	}
	if(ans < m)
	{
		flag[++cut] = sum;
		dfs(a[y + 1],y + 1);
	}
	if(ans > m)
	{
		cout << max(s,flag[cut - 1]);
		exit(0); 
	}
	else if(ans == m)
	{
		s = max(sum,s);
		dfs(a[y + 1],y + 1);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	dfs(a[0],0);
	return 0;	
} 
