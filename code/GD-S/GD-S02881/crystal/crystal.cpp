#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[1000000000005];
int cnt=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=0;i <= n;i++)
	{
		cin >> a[i];
	}
	cout << a[1] + a[2];
	return 0;
}
