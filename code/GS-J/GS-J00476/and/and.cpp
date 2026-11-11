#include<bits/stdc++.h>

using namespace std;
int num[200005];
bool cmp(int a, int b)
{
	return a >= b;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(m == 1)
	{
		int ma = 0;
		for(int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			ma = max(ma, tmp);
		}
		cout << ma;
		return 0;
	}
	else if(m == n)
	{
		int a, b;
		cin >> a >> b;
		int ans = a & b;
		for(int i = 1; i <= n - 2; i++)
		{
			int tmp;
			cin >> tmp;
			ans &= tmp;
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		cin >> num[i];
	sort(num + 1, num + 1 + n, cmp);
	int p = num[1], q = num[2];
	int ans = p & q;
	for(int i = 3; i <= m; i++)
		ans &= num[i];
	cout << ans;
	return 0;
 } 
