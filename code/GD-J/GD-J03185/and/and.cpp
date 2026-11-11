#include <bits/stdc++.h>
using namespace std;

long long a[200005];
string c[200005];

string in(long long k)
{
	string ans = "";
	string key = "";
	while(true)
	{
		if(k == 0) break;
		ans += (k % 2) +'0';
		k /= 2;
	}
	for(int i = ans.size() - 1;i >= 0;i--)
	{
		key += ans[i];
	}
	return key;
}

string A(string a,string b)
{
	string k1 = "",k2 = "",key = "",key2 = "";
	for(int i = a.size() - 1;i >= 0;i--)
	{
		k1 += a[i];
	}
	for(int i = b.size() - 1;i >= 0;i--)
	{
		k2 += b[i];
	}
	for(int i = 0;i < max(k1.size(),k2.size());i++)
	{
		if(k1[i] == k2[i])
		{
			if((k1[i] - '0') == 1) key += '1';
			else key += '0';
		}
		else key += '0';
	} 
	for(int i = key.size() - 1;i >= 0;i--)
	{
		key2 += key[i];
	}
	return key2;
}

long long o(string k)
{
	long long mul = 1,cnt = 0;
	for(int i = k.size() - 1;i >= 0;i--)
	{
		cnt += (k[i] - '0') * mul;
		mul *= 2;
	}
	return cnt;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,k;
	cin >> n >> k;
	long long maxn = 0;
	long long maxn2 = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);
		c[i] = in(a[i]);
	}
	if(k == 1) 
	{
		cout << maxn;
		return 0;
	}
	if(k == 2)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				maxn2 = max(o(A(c[i],c[j])),maxn2);
			}
		}
		cout << maxn2;
		return 0;
	}
	if(k == n)
	{
		string l = c[1];
		for(int i = 2;i <= n;i++)
		{
			l = A(l,c[i]);
		}
		cout << A(c[2],c[1]);
		return 0;
	}
	sort(a + 1,a + n + 1);
	cout << a[k];
	return 0;
}
