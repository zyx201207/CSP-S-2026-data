#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> n >> d;
		for(int j=1;j<=n;j++)
		{
			cin >> x[j];
		}
		long long cha=x[2]-x[1];
		if(d/cha>=2) cha=d/cha*2;
		else {
			cout << 0 << '\n';
			continue;
		}
		if(cha>n) cout << 0 << '\n';
		else cout << n-cha+1 << '\n';
	}
	return 0;
}
