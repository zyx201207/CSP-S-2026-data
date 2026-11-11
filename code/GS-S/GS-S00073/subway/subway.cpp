#include <bits/stdc++.h>
using namespace std;
int l,n,m,d,q,a[500005],b[500005],c[500005];
int m1,m2,t1,t2;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> l >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= m+2;i++)
	{
		cin >> b[i];
	}
	for (int i = 1;i <= m+2;i++)
	{
		cin >> c[i];
	}
	cin >> m1 >> m2;
	cin >> t1 >> t2;
	cout << m1*m2+t1*t2 << m1+m2+t1+t2;
	return 0;
}
