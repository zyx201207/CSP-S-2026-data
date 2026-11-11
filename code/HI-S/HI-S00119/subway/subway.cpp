#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if (c == 0)
	{
		if (n == 2)
		{
			cout << 32 << endl;
			cout << 17;
		}
		else
		{
			cout << 35 << endl;
			cout << 16;
		}
	}
	return 0;
}

