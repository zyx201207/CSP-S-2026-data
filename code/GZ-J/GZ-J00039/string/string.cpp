#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],sum;
char x[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> x[i];
	}
	if(x[n] == 'a')
	{
		if(a[1] == a[n])
		{
			cout << sum;
		}
	}
	else
	{
		sum += a[1];
		cout << sum;
	}
	return 0;
}
