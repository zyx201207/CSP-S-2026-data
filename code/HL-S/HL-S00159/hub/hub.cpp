#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long  a[15];
	long long  b[15];
	long long  suma = 0,sumb =0;
	for(int i = 1;i <= 10;i ++)
	{
		cin >> a[i] >> b[i];
		suma += a[i];
		sumb += b[i];
	}
	cout << abs(suma - sumb); 
	return 0;
 } 
