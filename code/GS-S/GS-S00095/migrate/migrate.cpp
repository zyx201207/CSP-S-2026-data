#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	long long n,d,a[100000],num = 0;
	for (int i = 0; i < t; i++){
		cin >> n >> d;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++){
				long long e = a[j] - a[i];
				if (e == d  + 1)
				{
					num++;
				}
			}
		}
		cout << num;
	}
	return 0;
}
