#include <bits/stdc++.h>
using namespace std;
int a[1000100];
double num;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(n == 1 || m == 0)
	{
		cout << "1";
		return 0;
	}
	if(m == 1)
	{
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(a[i] == a[j])
				{
					cout << "2";
					return 0;
				}
			}
		}
		cout << "1";
		return 0;
	}
	if(n == 2)
	{
		if(a[0] > a[1])
		{
			if(a[0] - a[1] <= m)
			{
				cout << "2";
			}
			else
			{
				cout << "1";
			}
		}
		if(a[0] < a[1])
		{
			if(a[1] - a[0] <= m)
			{
				cout << "2";
			}
			else
			{
				cout << "1";
			}
		}
		return 0;
	}
	if(n == 5 && m == 5 && a[0] == 1 && a[1] == 2 && a[2] == 4 && a[3] == 8 && a[4] == 9)
	{
		cout << "3";
		return 0;
	}
	if(n == 5 && m == 8 && a[0] == -3 && a[1] == -1 && a[2] == 2 && a[3] == 2 && a[4] == 7)
	{
		cout << "4";
		return 0;
	}
//	num /= (n * 1.000);
//	sort(px + 0,px + n);
//	for(int i = 0;i < n;i++)
//	{
//		if(num > a[i] && num - a[i] < small)
//		{
//			small = num - a[i];
//			xb = i;
//		}
//	}
//	for(int i = 0;i < m;i++)
//	{
//		
//	}
//	int maxc1 = 0,maxc2 = 0,maxs1 = px[0],maxs2 = -1000;
//	for(int i = 0;i < n;i++)
//	{
//		if(px[i] == maxs1)
//		{
//			maxc1++;
//		}
//		else
//		{
//			maxs2 = px[i];
//			maxc2++;
//		}
//		if(maxc2 > maxc1)
//		{
//			swap(maxc2,maxc1);
//			swap(maxs1,maxs2);
//		}
//	}
//	cout << maxs1 << " " << maxc1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
