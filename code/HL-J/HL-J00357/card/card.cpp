#include <iostream>
using namespace std;
int m,n,a[1000000],b[1000000];
int main()
{
	cin >> m >> n;
	int num[n+100];
	for (int i = 1;i <= m;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= m;i++)
	{
		b[i] = a[i];
		for (int j = 1;j <= i;j++)
		{
			if (a[i] == b[j])
			{
				for (int z = j;z <= i;z++)
				{
					b[z] = 0;
				}
			}
		}
		for (int j = 1;j <= i;j++)
		{
			num[b[j]]++;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		cout << num[i];
	}
}
