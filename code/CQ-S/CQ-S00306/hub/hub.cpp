#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c , t;
	cin >> c >> t;
	while(t--)
	{
		int n , k;
		cin >> n >> k;
		for(int i = 1;i < n;i++)
		{
			int u , v;
			cin >> u >> v;
		}
		cout << (n - k) / 3 << endl;
	}
	return 0;
}

