#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int n, k;
int T;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		int x = (n + 1) / 2;
		cout << x / 4 + 1 << endl;
	}
	
	
	return 0;
}
