#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;
pair <int,char > d[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int len = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> d[i].first >> d[i].second;
		len += d[i].first;
	}
	bool flag = true;
	char ch = d[1].second;
	for (int i = 2;i <= n;i++)
	{
		if (d[i].second != ch)
		{
			flag = false;
			break;
		}
	}
	bool flag2 = true;
	for (int l = 1,r = n;l <= r;l++,r--)
	{
		if (d[l].first != d[r].first || d[l].second != d[r].second)
		{
			flag2 = false;
			break;
		}
	}
	if (flag || flag2)
	{
		cout << 0 << endl;
		return 0;
	} 
	int zj = (len + 1) / 2;
	int zj_i = 1;
	int sum = 0;
	while (sum <= zj)
	{
		sum += d[zj_i].first;
		zj_i++;
	}
	int need;
	if (sum != zj)
	{
		need = zj - (sum - d[zj_i].first);
		zj_i--;
	}
	else
		need = 0;
	vector <pair <int,char > > q,h;
	for (int i = 1;i < zj_i;i++)
		q.push_back(d[i]);
	q.push_back(make_pair(need,d[zj_i].second));
	h.push_back(make_pair(d[zj_i].first - need,d[zj_i].second));
	for (int i = zj_i + 1;i <= n;i++)
		h.push_back(d[i]);
	int q_p = 0,h_p = n - zj_i;
	pair <int,int > zg;
	int zh = 0;
	while (q_p < zj_i && h_p >= 0)
	{
		if (q[q_p].second != h[h_p].second)
		{
			zh += q[q_p].first;
			int cnt = 0;
			while (cnt <= q[q_p].first)
			{
				cnt += h[h_p].first;
				h_p--;
			}
			int xy;
			if (cnt == q[q_p].first)
				xy = 0;
			else
			{ 
				xy = q[q_p].first - (cnt - h[h_p].first);
				h_p++;
			}
			h[h_p - 1].first -= xy;
			q_p++;
		}
		else
		{
			if (q[q_p].first == h[h_p].first)
			{
				q_p++;
				h_p--;
			}
			else if (q[q_p].first > h[h_p].first)
			{
				q[q_p].first -= h[h_p].first;
				h_p--;
			}
			else
			{
				h[h_p].first -= q[q_p].first;
				q_p++;
			}
		}
	}
	cout << zh << endl;
	return 0;
}
