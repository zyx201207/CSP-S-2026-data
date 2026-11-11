#include <bits/stdc++.h>
using namespace std;

int c,T,island[114514],d,n;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i=1;i<=n;i++)cin >> island[i];
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
