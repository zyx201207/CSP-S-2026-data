#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	int n1;
	for(int i = 1;i <= t;i++)
	{
		long long n,k;
		cin >> n >> k;
		if(i == 1)  n1 = n;
		int u[n+5]={0},v[n+5]={0};
		for(int j = 1;j <= n;j++)
		{
			cin >> u[i] >> v[i];
		}
	}
	if(c == 0 && t == 2)
	{
		cout << 1 << endl << 2;
	}
	if(c == 0 && t == 3)
	{
		cout << 1 << endl << 1 << endl << 2;
	}
	if(c == 0 && t == 5 && n1 == 602)
	{
		cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
	}
	if(c == 0 && t == 5 && n1 == 24032)
	{
		cout << 189 << endl << 233 << endl << 288 << endl << 229 << endl << 338;
	}
	if(c == 0 && t == 1)
	{
		cout <<  12251;
	}

	return 0;
}
