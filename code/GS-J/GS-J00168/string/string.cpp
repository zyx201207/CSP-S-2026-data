#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long m = 0,l = 0;
    cin >> n;
    int a[n+5];
    char c[n+5];
    for (int i = 1;i <= n;i++)
    {
    	cin >> a[i] >> c[i];
    	m += a[i];
	}
    if (m%2==0)
    {
    	l = m / 2;
	}
	else
	{
		l = m / 2 + 1;
	}
	cout << m - l; 
    return 0;
}
