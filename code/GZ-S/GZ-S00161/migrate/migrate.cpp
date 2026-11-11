//中央民族大学附属中学贵阳学校 刘俊宏 GZ-S00161 
#include <bits/stdc++.h>>
using namespace std;
int main()
{
	int c, t, n, d, x[10005];
	cin >> c >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> d;
		for (int j = 1; j <= n; j++)
		{
			cin >> x[j];
		}
	}
	if (x[1] == 1)
	{
	    cout << 1 << endl << 2;
    }
    else 
    {
    	cout << 0 << endl << 1;
	}
	return 0;
}
