#include <iostream>
#include <deque>
#include <vector>
using namespace std;
#define ll long long
const int N = 2e5+5;
deque<pair<int,char>> dq;
int a[N];
char c[N];
vector<pair<int,char>> fr,bk;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		dq.push_back({a[i],c[i]});
	}
	while (!dq.empty())
	{
		pair<int,char> u = dq.front();
		pair<int,char> v = dq.back();
		dq.pop_front();
		if (!dq.empty()) dq.pop_back();
		else break;
		if (u.first > v.first)
		{
			fr.push_back({v.first,u.second});
			bk.push_back({v.first,v.second});
			dq.push_front({u.first-v.first,u.second});
		}
		else if (v.first > u.first)
		{
			fr.push_back({u.first,u.second});
			bk.push_back({u.first,v.second});
			dq.push_back({v.first-u.first,v.second});
		}
		else
		{
			fr.push_back({u.first,u.second});
			bk.push_back({u.first,v.second});
		}
	}
	ll ans = 0;
	for (int i = 0; i < fr.size(); i++)
	{
		if (fr[i].second != bk[i].second) ans += fr[i].first;
	}
	cout << ans;
	return 0;
}


