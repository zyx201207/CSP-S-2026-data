#include <bits/stdc++.h>
using namespace std;

int cnt;
int main()
{
	//freopen("card.in", "r", stdin);//±ðÍüÈ¥×¢ÊÍ 
	//freopen("card.out", "w", stdout); 
	int n, m;
	int a[100000000];
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i + 1] < a[i])
		{
			cnt = a;
			cnt = 0;
		}
		else
		{
			cnt += a[i];
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << a;
	}
	
	return 0;
}
