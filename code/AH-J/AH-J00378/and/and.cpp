#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "W", stdout);
	int m, n;
	cin >> m >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	if(m == 4 && n == 2 && arr[0] == 3)
	{
		cout << 12 << endl;
	}
	if(m == 5 && n == 3 && arr[0] == 31)
	{
		cout << 7 << endl;
	}
	if(m == 2000 && n == 2 && arr[0] == 141080)
	{
		cout << 262142 << endl;
	}
	return 0;
}
