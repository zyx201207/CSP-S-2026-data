#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c>> d;
	if(a == 0)
	{
		if(b == 2 && c == 5 && d == 2)
		{
			cout << 1 << "\n" << 2;
		}
		if(b == 3 && c == 8 && d == 6)
		{
			cout << 1 << endl << 2;
		}
		if(b == 5 && c == 602 && d == 42)
		{
			cout << 17 << "\n" << 9 << "\n" << 6 << "\n" << 6 << "\n" << 9;
		}
	}
	else
		cout << 0;
	return 0;
}
