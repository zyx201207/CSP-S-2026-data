//中央民族大学附属中学贵阳学校 刘俊宏 GZ-J00227
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m=0, a[100005], b[100005], s=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n;i++)
	{
		m += a[i];
	}
	for (int j = 0; j <= m/2; j++)
	{
		if (b[j] != b[m-j])
		{
			s++;
		}
	}
	cout << s;
	return 0;
} 
