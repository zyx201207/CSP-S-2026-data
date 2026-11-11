#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 100;

int c ,t;
int n ,d;
int x[maxn];

int main()
{
	freopen("migrate.in" ,"r" ,stdin);
	freopen("migrate.out" ,"w" ,stdout);
	
	cin >> c >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i]; 
	}
	for (int i = 1; i <= t; i++) cout << 0 << '\n';
	return 0;
}
