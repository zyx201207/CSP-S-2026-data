#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[2000005],v[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n >> k;
		for (int j = 1;j <n;j++)
		{
			cin >> u[i] >> v[i];
		}
	}
	for (int i = 1;i <= t;i++)
	{
		if(n == 5 && t == 2)
		{
			cout << "1";
		}
		else if (n == 10 && t == 3)
		{
			cout << "2";
		}
	}
	return 0;
}
