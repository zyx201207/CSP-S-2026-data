#include <bits/stdc++.h>
using namespace std;
char m[200005];
int a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int sum=0;
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		int x;
		char y;
		cin >>x >> y;
		for (int j = 1;j <= x;j++)
		{
			m[a+1]=y;
			a++;
		}
	}
	for (int i = 1;i <= a/2;i++)
	{
		if (m[i]!=m[a-i+1])
		{
			sum += 1;
		}
	}
	cout << sum;
	return 0;
}
