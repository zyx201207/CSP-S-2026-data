#include <bits/stdc++.h>
using namespace std;
int b, i, i2, i3, d, e = 0, g;
char a[200005], c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> g;
	for(i = 1;g >= i;i++)
	{
		cin >> b;
		cin >> c;
		d += b;
		for(i2 = 1;b >= i2;i2++)
		{
			i3++;
			a[i3] = c;
		}
	}
	for(i = 1;d / 2 >= i;i++)
		if(a[i] != a[d - i])
			e++;
	cout << e;
	return 0;
}
