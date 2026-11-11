#include <bits/stdc++.h>
using namespace std;
int n,len;
char a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int num;
		char c;
		for (int j = 1; j <= num; j++)
		{
			len++;
			a[len] = c;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= (len+1)/2; i++)
	{
		if (a[i] != a[len+1-i])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
