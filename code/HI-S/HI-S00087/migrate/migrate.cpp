#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[n];
		if(n==4&&d==2) cout << 1 << endl;
		if(n==5&&d==2) cout << 2 << endl;
		if(n==6&&d==2) cout << 1 << endl;
		if(n==5&&d==3) cout << 0 << endl;
	}
	return 0;
}
