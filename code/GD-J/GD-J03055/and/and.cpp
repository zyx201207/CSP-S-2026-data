#include <bits/stdc++.h>
using namespace std;

int cnt[35];
string s[200005];
bool flag[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		string now = "";
		while(x > 0)
		{
			if(x & 1) now = now + '1';
			else now = now + '0';
			x >>= 1;
		}
		while(now.size() < 32) now = now + '0';
		s[i] = now;
		//cout << now << endl;
	}
	for(int i = 1; i <= n; i++)
	{
		string x = s[i];
		for(int j = x.size() - 1; j >= 0; j--) if(x[j] == '1') cnt[j]++;
	}
	for(int i = 1; i <= n; i++) flag[i] = 1;
	//for(int i = 31; i >= 0; i--) cout << cnt[i] << " ";
	//cout << endl;
	int sum = 0;
	int now;
	for(int i = 31; i >= 0; i--)
	{
		now = 1 << i;
		if(cnt[i] >= m) 
		{
			sum += now;
			for(int j = 1; j <= n; j++)
			{
				string x = s[j];
				if(x[i] == '1' && flag[j]) flag[j] = 1;
				else 
				{
					if(flag[j])
					{
						for(int k = x.size() - 1; k >= 0; k--) if(x[k] == '1') cnt[k]--;
						flag[j] = 0;
					}
				}
			}
		}
//		for(int j = 31; j >= 0; j--) cout << cnt[j] << " ";
//		cout << endl;
	}
	cout << sum;
	return 0;
}
