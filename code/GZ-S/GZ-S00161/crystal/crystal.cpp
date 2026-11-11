//中央民族大学附属中学贵阳学校 刘俊宏 GZ-S00161 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, a[100005];
	int c = 1;
	cin >> n >> m;
	for (int i = 1; i <= n;i ++)
	{
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++)
	{
		int s = 0;
		if (a[i-1]<a[i])
		{
			s += a[i];
			s -= a[i-1];
			m -= s;
			if (m < 0)
			{
				break;
			}
			else
			{
				a[i-1]=a[i];
	       	}
		}
		if (a[i-1] == a[i])
		{
			c++;
		}
    }
    cout << c;
    return 0;
}
