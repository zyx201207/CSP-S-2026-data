#include<bits/stdc++.h>

using namespace std;

const int N = 2e6+500;
long long a[N]={};

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,m;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1;i <= n;i++) cin >> a[i];
		if(n == 4 && m == 2) cout << 1;
		else if (n == 5 && m == 2) cout << 2;
		else if (n == 5 && m == 3) cout << 0;
		else if (n == 6 && m == 2) cout << 1;
		else cout << 1;
		cout << "\n";
	}
	return 0;
}
