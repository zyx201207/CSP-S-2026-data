#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[200001];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int t = a[i];
		for (int j = i; j < i+m; j++)
		{
			t &= a[j];
		}
		ans = max(ans, t);
	}
	cout << ans;
	return 0;
}
