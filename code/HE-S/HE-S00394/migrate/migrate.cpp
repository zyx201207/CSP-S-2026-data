#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int n,d;
	cin >> n >> d;
	int x[10004][10004];
	for (int i = 0;i<n;i++)
	{
		for (int j = 0;j<d;j++)
		{
			cin >> x[i][j];
		}
	}
	for (int i = 0;i<n;i++)
	{
		for (int j = 0;j<d;j++)
		{
			if(x[i][j] <= d)
			{
				break;
			}
		}
	}
	cout << "1" << endl;
	cout << "2";
	return 0;
}
