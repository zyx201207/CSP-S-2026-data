#include <iostream>
#include <algorithm>
using namespace std;
long long a[200005];
int n , m;
long long ans = 0;
bool vis[200005];
void guei(int cnt , long long shu)
{
	if (cnt == m)
	{
		ans = max(ans , shu);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			long long x = a[i] & shu;
			guei(cnt + 1 , x);
			vis[i] = false;
		}
	}
	return ;
} 
int main()
{
	
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		vis[i] = true;
		guei(1 , a[i]);
		vis[i] = false;
	}
	
	cout << ans;
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12
*/
