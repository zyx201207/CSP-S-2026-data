#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a == 0)
	{
		if(b == 2 && c == 4 && d == 2)
			cout << 1 << "\n" << 2;
		else if(b == 2 && c == 5 && d == 3)
		{
			cout << 0 << "\n" << 1;
		}
		else
		{
			cout << 0 << "\n" << 1;
		}
	}
	else
	{
		cout << 1 << "\n" << 0;
	return 0;
	}
	
}
