#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[500005] , h[300005] , ans[300005];
struct node
{
	int l , r , id;
}qj[300005];
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		h[a[i]] = i;
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i; j <= n; j ++)
		{
			ans[a[j]] ++;
			j = h[a[j]];
		}
	}
	for(int i = 1; i <= m; i ++)cout << ans[i] << " ";
	return 0;
}
