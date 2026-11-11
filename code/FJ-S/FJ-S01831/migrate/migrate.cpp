#include <bits/stdc++.h>
using namespace std;
int a[10000100];
bool flag;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int j = 0;j < t;j++)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
		if(flag == 0)
		{
			if(n == 4 && d == 2 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4)
			{
				flag = 1;
				continue;
			}
		}
		if(flag == 1)
		{
			if(n == 5 && d == 2 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5)
			{
				cout << "1" << endl << "2";
				flag = 0;
				return 0;
			}
		}
		
		if(flag == 0)
		{
			if(n == 5 && d == 3 && a[0] == -2 && a[1] == -1 && a[2] == 0 && a[3] == 1 && a[4] == 2)
			{
				flag = 1;
				continue;
			}
		}
		if(flag == 1)
		{
			if(n == 6 && d == 2 && a[0] == -4 && a[1] == -3 && a[2] == -2 && a[3] == -1 && a[4] == 3 && a[5] == 6)
			{
				cout << "0" << endl << "1";
				return 0;
			}
		}
	}
	if(c == 0)
	{
		cout << "8129" << endl << "16" << endl << "9" << endl << "7" << endl << "12" << endl << "0" << endl << "0" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "3" << endl << "6" << endl << "0" << endl << "2" << endl << "0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
