#include <bits/stdc++.h>
#define N 2010
using namespace std;
struct node
{
	string s;
	int num;
	bool operator <(const node o) const
	{
		return num > o.num;
	}
};
int n,m,ans,a[N],pre[31];
string s[N];
vector<node> v;
string f2(int x)
{
	string s = "";
	while (x)
	{
		int t = x % 2;
		s = (char)(t + '0') + s;
		x /= 2;
	}
	while (31 - (int)s.size()) s = '0' + s;
	return s;
}
int f10(string x)
{
	int ans = 0;
	for (int i = (int)x.size() - 1,power = 1;i >= 0;--i,power *= 2) ans += power * (x[i] - '0');
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;++i)
	{
		cin >> a[i];
		s[i] = f2(a[i]);
	}
	for (int i = 1;i <= n;++i)
		for (int j = 0;j < (int)s[i].size();++j)
			if (s[i][j] == '1') ++pre[j];
	for (int i = 0;i <= 30;++i)
	{ 
		if (pre[i] >= m)
		{
			for (int j = 1;j <= n;++j)
				if (s[j][i] == '1')
				{
					int num = 0;
					for (char c : s[j])
						if (c == '1') ++num;
					v.push_back({s[j],num});
				}
			break;
		}
	}
	sort (v.begin(),v.end());
	ans = f10(v[0].s);
	for (int i = 1;i < m;++i) ans &= f10(v[i].s);
	cout << ans;
	return 0;
}
