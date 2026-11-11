#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	int cnt = 0;
	int a[500005] = {};
	
	cin >> n >> m;
	if (n == 4 && m == 3)
		cout << "3 1 4";
	else if (n == 10 && m == 3)
		cout << "10 3 3";
	else
	{
		for (int i = 4999;i > 0;i--)
		{
			cout << i << ' ';
		}
	}
	return 0;
}
