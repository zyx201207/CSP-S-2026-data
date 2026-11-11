#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	if (c == 0)
	{
		int a = 1,b = 2;
		cout << a << endl << b;
	}
	else
	{
		for (int i = 1;i <= t;i++)
		{
			cout << i;
		}
	}
	return 0;
}

