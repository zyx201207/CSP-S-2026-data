#include <bits/stdc++.h>
using namespace std;
long long n,a,s = 0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char c;
    cin >> n;
    string x;
    for (long long i = 1;i <= n;i++)
    {
        cin >> a >> c;
        for (int j = 1;j <= a;j++)
        {
			x += c;
		}
    }
    long long si = x.size();
    for (long long i = 0;i < si / 2;i++)
    {
		if (x[i] != x[si - i - 1])
		{
			s++;
		}
	}
	cout << s;
    return 0;
}
