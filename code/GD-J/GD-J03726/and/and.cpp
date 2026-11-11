#include <bits/stdc++.h>
using namespace std;

int n, m;
int s[100100];
string str[200005];
int strcnt = 1;
int maxn = -0x3f3f3f3f;

int two(int ds, int ts)
{
	int usum = 1;
	
	while (ts--)
	{
		usum *= ds;	
	}	
	return usum;
}

int two_to_ten(string num)
{
	int retur = 0;
	int numlen = num.size();
	int zs = 0;
	
	while (numlen--)
	{
		int modsum = num[numlen] - '0';
		retur += two(modsum, zs);
		zs++;
	}
	
	return retur;
}

void ten_to_two(int sum)
{
	string twostr = "";
	
	while (sum)
	{
		int sum_mod_two = sum % 2;
		twostr += char(sum_mod_two + '0');
		sum /= 2;
	}
	
	reverse(twostr.begin(), twostr.end());
	str[strcnt++] = twostr;
	//cout << twostr;
}

int a_and_b (string a, string b)
{
	int lena = a.size();
	int lenb = b.size();
	string answer = "";
	
	int l = lena, r = lenb;
	while (l && r)
	{
		int ll = a[l], rr = a[r];
		if (l < 0)
		{
			ll = '0';
		}
		if (r < 0)
		{
			rr = '0';
		}
		if (ll == rr) answer += '1';
		else answer += '0';
		l--,r--;
	}
	reverse(answer.begin(), answer.end());
	return two_to_ten(answer);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		ten_to_two(s[i]);
	}
	if (m == 1)
	{
		int maxn = -0x3f3f3f3f, maxn_ = 0;
		for (int i = 1; i <= n; i++)
		{
			if(s[i] > maxn)
			{
				maxn = s[i];
				maxn_ = i;
			}
		}
		cout << maxn_;
		return 0;
	}
	if (m == 2)
	{
		int maxn = -0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				else
				{
					int jg = a_and_b(str[i], str[j]);
					maxn = max(maxn, jg);
				}
			}
		}
		cout << maxn;
		return 0;
	}
	return 0;
}
