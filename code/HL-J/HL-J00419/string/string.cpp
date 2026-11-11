#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
string a,b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i= 1;i <= n;i++)
	{
		cin >> m;
		cin >> b;
		for(int j = 1;j <= m;j++)
		{
			a += b;
		}
	}

	for(int i = 0;i < (a.size() / 2);i++)
	{
		if(a[i] != a[a.size() - i - 1])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;


}

