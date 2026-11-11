#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c , t;
	cin >> c >> t;
	while(t--)
	{
		cout << (rand() % M) << "\n";
	}
	return 0;
}
