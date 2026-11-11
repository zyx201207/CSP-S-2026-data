#include <bits/stdc++.h>
using namespace std;
int n,m;
long long dog[1000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> dog[i];
	}
	cout << dog[3];
    return 0;
}
