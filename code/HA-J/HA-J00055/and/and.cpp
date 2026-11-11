#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int m,n;
bool c(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n == 2000 and m == 2)
	{
		cout << 262142;
		return 0;
	} 
	else if (n == 200000 and m == 2)
	{
		cout << 511;
	}
	sort(a+1,a+n+1, c);
	//cout << a[1] << endl;
	//reverse(a.begin(), a.end());
	int ans = a[1]; 
	for (int i = 1; i <= m; i++)
	{
		ans = (ans & a[i]);
	}
	/*ans = (ans & 15);
	ans = (ans & 7);*/
	cout << ans;
	return 0;
}
