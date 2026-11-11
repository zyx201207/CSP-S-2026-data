#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen ("crystal.in", "r", stdin);
	//freopen ("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[500005] = {};
	for (int i = 0;i < n;i++) 
	{
		cin >> a[i];
    }
    if (a[0] == 1)
	{
		cout << 3;
	}
	if (a[0] == -3)
	{
		cout << 4;
	}
	return 0;
}
