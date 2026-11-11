#include <bits/stdc++.h>
using namespace std;
int main ()
{
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	char x;
	int n, m, sum = 0, num = 0;
	cin >> n;
	char str[1000000] = {};
	for (int  i = 1; i <= n; i ++)
	{
		cin >> m >> x;
		num += m;
		for (int j = 1; j <= n; j ++)
		{
			str[j] = x;
		}
	}
	for (int i = 1; i <= num / 2 + 1; i ++)
	{
		if (str[i] == str[n - i])
		{
			continue;
		}
		else 
		{
			str[n - i] = str[i];
			sum ++;
		}
	}
	cout << sum - 1;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
