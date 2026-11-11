#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
struct Para
{
	long long num;
	char c;
};
Para a[200005];
vector<Para> le;
int cnt1[130], cnt2[130];
void speedup()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	speedup();
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].num >> a[i].c;
		sum += a[i].num;
	}
	long long tar = sum / 2;
	long long have = 0;
	int cur;
	for (int i = 1; i <= n; i++)
	{
		if (have + a[i].num <= tar)
		{
			have += a[i].num;
			le.push_back({a[i].num, a[i].c});
		}
		else if (tar - have != 0)
		{
			le.push_back({tar - have, a[i].c});
			cnt1[a[i].c] += a[i].num - tar + have;
			cur = i;
			have = tar;
			break;
		}
	}
	reverse(le.begin(), le.end());
	for (int i = cur; i <= n; i++) cnt1[a[i].c] += a[i].num;
	for (int i = 0; i < le.size(); i++) cnt2[le[i].c] += le[i].num;
	long long ans = 0;
	for (int i = 'a'; i <= 'z'; i++) ans += (cnt2[i] - cnt1[i]);
	cout << ans << endl;
	return 0;
}
