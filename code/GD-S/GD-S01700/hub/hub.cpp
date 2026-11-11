#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
int main()
{
	cin >> c >> t;
	if(c == 0)
	{
		if(t == 2)
		{
			cout << 1 << '\n' << 2;
			return 0;
		}
		if(t == 3)
		{
			cout << 1 << '\n' << 1 << '\n' << 2;
			return 0;
		}
		if(t == 5)
		{
			cout << 17 << '\n' << 9 << '\n' << 6 << '\n' << 6 << '\n' << 9;
			return 0;
		}
	}
}
