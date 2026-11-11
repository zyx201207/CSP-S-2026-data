#include<bits/stdc++.h>
using namespace std;
int n , m , a[200005] , b[200005];
long long max_a = -1;
void dfs(int idex , int ids)
{
	if(ids == m + 1 || idex > n)
	{
		long long sum = b[1];
		for(int i = 2 ; i <= m ; i ++)
		{
			sum = (sum & b[i]);
		}
		max_a = max(max_a , sum);
		return;
	}
	b[ids] = a[idex];
	dfs(idex + 1 , ids + 1);
	b[ids] = 0;
	dfs(idex + 1 , ids);
	return;
}
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	if(m == 1)
	{
		sort(a + 1 , a + n + 1);
		cout << a[n];
		return 0;
	}
	dfs(1 , 1);
	cout << max_a;
	return 0; 
}
