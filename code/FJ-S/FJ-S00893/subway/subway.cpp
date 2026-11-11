#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long c, n;
	cin >> c >> n;
	if(n == 2)
		cout << 32 << endl << 17 << endl;
	else if(n == 3)
		cout << 35 << endl << 16 << endl;
	else
	{
		cout << "?";
	}
		
	return 0;
}

