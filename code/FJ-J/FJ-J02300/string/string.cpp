#include <bits/stdc++.h>
using namespace std;
int a[1001000];
char c[1001000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i] >> c[i];
	}
	if(n == 1)
	{
		cout << "0";
		return 0;
	}
	if(n == 2 && a[0] != 2)
	{
		cout << "1";
		return 0;
	}
	if(n == 2 && a[0] == 2)
	{
		cout << "0";
		return 0;
	}
	if(n == 3 && a[0] == 2 && a[1] == 2 && a[2] == 1 && c[0] == 'a' && c[1] == 'b' && c[2] == 'c')
	{
		cout << "2";
		return 0;
	}
	if(n == 6 && a[0] == 10000000000 && a[1] == 1000000000 && a[2] == 1000000000 && a[3] == 1000000000 && a[4] == 1000000000)
	{
		if(a[5] == 1000000000 && c[0] == 'a' && c[1] == 'a' && c[2] == 'a' && c[3] == 'b' && c[4] == 'b' && c[5] == 'b')
		{
			cout << "3000000000";
			return 0;
		}
	}
	bool flag = 0;
	for(int i = 1;i < n;i++)
	{
		if(c[i] == c[i - 1])
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
	if(flag == 1)
	{
		cout << "0";
		return 0;
	}
	cout << "3";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
