#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long sum = 0, cnt = 0;
	char a[1000000005];
	stack<char> f;
	for (int i = 1; i <= n; i++)
	{
		int num;
		char s;
		cin >> num >> s;
		for (int j = sum; j <= sum + num - 1; j++)
		{
			a[j] = s;
		}
		sum += num;
	}
	for (int i = 0; i <= (sum + 1) / 2; i++)
	{
		f.push(a[i]);
	}
	if (sum % 2 == 1)
	{
		f.pop();
	}
	for (int i = (sum + 1) / 2; i < sum; i++)
	{
		if (f.top() == a[i])
		{
			f.pop();
		}
		else
		{
			cnt++;
			f.pop();
		}
	}
	cout << cnt;
	return 0;
 } 
