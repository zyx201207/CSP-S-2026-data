#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
vector<ull> v;
ull n,m;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int  i = 0;i < n;i++)
	{
		ull a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	ull ba = v[v.size()-1];
	for (int i = v.size()-1;i > v.size()-1-m;i--)
	{
		ba &= v[i];
	}
	cout << ba;
}
