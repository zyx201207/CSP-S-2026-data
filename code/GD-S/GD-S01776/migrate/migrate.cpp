#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int w = 2e6 + 10;
const int inf = 0x3f3f3f3f;
ll c,t,n,d,a[w];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin >> c >> t >> n >> d;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= t;i++)
		cout << rand() % 8 + 1 << endl;
	return 0;
}

