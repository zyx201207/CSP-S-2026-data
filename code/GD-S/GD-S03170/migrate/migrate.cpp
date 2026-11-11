#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --)
	{
		int n, d, cnt = 0;
		cin >> n >> d;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++)
			cin >> a[i];
		for(int i = 1; i <= n; i ++)
			for(int j = i + 1; j <= n; j ++)
				if(a[j] - a[i] == 2 * d - 1)
					cnt ++;
		cout << cnt << '\n';
	}
} 
