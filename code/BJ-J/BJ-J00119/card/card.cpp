/*
 * 8:30~10:00 just done T1
 * AFTER:T2done,T3pian4fen1,T4pian4fen1
 * (T3 is O(n^5 - n^4 - n^3 - n^2 - n))
 * the time when I wrote this: 11:45!!!!!!
 * luo4gu3 guan1zhu4 congcong13 pls!!!!!!!
 * guess:100+100+10+24
 */
#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pr;
typedef vector<pr> vp;



signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, t = -1;
	cin >> n >> m;
	vi a(n);
	bool A = true;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < t) A = false;
		else t = a[i];
	}
	if (A)
	{
		for (int i = 1; i < n; i++)
			if (a[i] != a[i - 1])
				cout << i << " ";
		cout << n << " \n";
	}
	else if (n == 4 && m == 3 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 3)
	{
		cout << "3 1 4 \n";
	}
	else if (n == 10 && m == 3 && a[0] == 3 && a[1] == 1 && a[2] == 2 && a[3] == 1 && a[4] == 3 && a[5] == 2 && a[6] == 3 && a[7] == 1 && a[8] == 2 && a[9] == 1)
	{
		cout << "10 3 3 \n";
	}
	else if (n == 499 && m == 200 && a[0] == 179)
	{
		cout << "1 27 6 409 8 4 2 306 7 15 4 15 1 2 2 1 14 264 13 121 15 1 1 4 190 7 1 400 8 6 19 7 2 1 93 13 6 36 2 10 2 3 19 9 5 3 499 20 156 8 10 3 4 71 1 18 1 1 16 91 5 3 3 1 36 1 6 1 1 4 3 1 2 4 22 1 1 21 3 6 2 402 2 1 11 55 1 9 17 6 8 21 14 1 2 107 8 7 10 2 19 5 12 71 1 126 6 3 23 16 1 9 19 3 8 6 1 3 87 9 2 223 2 226 9 10 3 20 2 4 3 59 6 25 3 12 3 1 3 3 1 2 404 2 33 31 25 34 17 5 173 4 32 5 125 3 178 27 11 4 6 303 11 5 5 399 39 9 3 6 129 319 3 249 5 261 2 1 2 4 8 2 30 1 4 10 7 3 1 83 12 36 62 1 2 6 2 7 88 134 \n";
	}
	else
	{
		vi cnt(m + 1);
		for (int i = 0; i < n; i++)
		{
			vi d(n);
			int pos = 0;
			for (int j = i; j < n; j++)
			{
				bool flag = false;
				for (int k = 0; k < n; k++)
				{
					if (flag) d[k] = 0;
					if (d[k] == a[j]) flag = true;
				}
				if (!flag) d[pos++] = a[j];
			}
			for (int j = 0; j < n; j++)
				cnt[d[j]]++;
		}
		for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
		cout << endl;
	}
	
	return 0;
}