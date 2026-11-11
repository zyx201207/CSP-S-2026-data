#include <bits/stdc++.h>
using namespace std;

int disabled = {};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	// ...
	int n = 0, m = 0;
	int a[50005] = {};
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	int final[n + 1][n + 1] = {};
	
	for (int i = 0; i < n; i++)
	{
		//cout << "第" << i << "局：" << endl;
		int sync = 0, flag = 0;
		for (int j = 0; j < (n - i); j++)
		{
			int k = a[j + i];
			//cout << "第" << j << "张牌，点数" <<  k << endl;
			for (int z = 0; z < j; z++)
			{
			//	cout << "!第" << z << "次探测, k = " << k << endl;
				if (flag == 0)
				{
					if (k == final[i][z])
					{
			//			cout << "发现 k = final[" << i << "][" << z << "] \n"; 
						flag = 1;
						final[i][z] = -1;
			//			cout << "标记 final[" << i << "][" << z << "] \n"; 
			//			cout << "final = " << final[i][z] << endl;
					}
				}
				else
				{
			//		cout << "标记 final[" << i << "][" << z << "] \n"; 
					final[i][z] = -1;
			//		cout << "final = " << final[i][z] << endl;
				}
			}
			flag = 0;
			final[i][j] = k;
			sync++;
		}
		//cout << "\n";
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n); j++)
		{
		//	cout << final[i][j] << ", ";
		}
		cout << endl;
	}
	*/
	for (int z = 1; z <= m; z++)
	{
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < (n - i); j++)
			{
				if (final[i][j] == z)
				{
					temp++; break;
				}
			}
		}
		//cout << "Temp: " << temp << " \n";
		cout << temp << " ";
	}
	
	return 0;
}
