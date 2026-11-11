#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N(2e5 + 5);
struct stu
{
	int num;
	char c;
} a[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].num >> a[i].c;
	} 
	for (int i = 1, j = n; i <= j;)
	{
		if (a[i].num > a[j].num)
		{
			while (a[i].num >= 0 && a[i].num > a[j].num && i <= j && a[j].num)
			{	
				if (a[i].c == a[j].c)
				{	
					a[i].num -= a[j].num;
					j--;
					continue;
				} 
//				cout << i << ' ' << j << ' ';				
				ans += a[j].num;
				a[i].num -= a[j].num;
				a[j].num = 0;
				j--; 
//				cout << ans << '\n';
			}
		}
		else if (a[j].num > a[i].num)
		{
			while (a[j].num >= 0 && a[j].num > a[i].num && i <= j && a[i].num)
			{
				if (a[i].c == a[j].c)
				{
					a[j].num -= a[i].num;
					i++;
					continue;
				}
//				cout << i << ' ' << j << ' '; 		
				ans += a[i].num;
				a[j].num -= a[i].num;
				a[i].num = 0;
				i++;
//				cout << ans << '\n';
			}
		}
		else
		{
			while (a[i].num == a[j].num && i <= j && a[i].num && a[j].num)
			{
				if (a[i].c != a[j].c)
				{
//					cout << i << ' ' << j << ' '; 
					ans += a[j].num;
//					cout << ans << '\n';
				}
				a[i].num = a[j].num = 0;
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}
