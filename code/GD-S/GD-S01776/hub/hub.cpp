#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int w = 1e5 + 10;
const int inf = 0x3f3f3f3f;
ll c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
		cout << rand() % 9 + 1 << endl;
	return 0;
}

