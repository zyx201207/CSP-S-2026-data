#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (long long i = 1;i <= m;i++)
    {
		if (i * (i + 1) / 2 >= m)
		{
		    cout << i;
		    return 0;	
		}
	}
    return 0;
}
