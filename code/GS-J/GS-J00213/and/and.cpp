#include<bits/stdc++.h>

using namespace std;
int n , m, a[200005] , mx = 0;

int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1 , greater<int>());
	for(int i = 2; i <= m; i++)
	{
		mx = a[i-1] & a[i];
	}
	cout << mx;
	return 0;
}
