#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in", "r", stdin);//±ðÍüÈ¥×¢ÊÍ 
	freopen("and.out", "w", stdout);
	int n, m;
	long long a[1000000000000];
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= m; i++)
	{
		int MINN;
		if(i + 1 <= m)
		{
			MINN = min(a[i], a[i + 1]);
		}	
	}
	cout << MINN;
	return 0;
}

