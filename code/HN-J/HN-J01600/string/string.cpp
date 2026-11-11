#include<bits/stdc++.h>
using namespace std; 
char b[200005];
long long a[200005];
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] % 2 == 0)
			sum += a[i];
	} 
	cout << sum / 2;
	return 0;
}
