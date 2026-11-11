#include<bits/stdc++.h>

using namespace std;

string s = " ";
char c;
long long n, l, cnt;
//pair<int, char> p[int(1e9 + 5)];

int main()
{
 	freopen("string.in", "r", stdin);
 	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> l >> c;
		//p[i] = {l, c};
		s.append(l, c);
	}
	for(int i = 1; i <= (s.size() - 1) / 2; i++)
	{
		if( s.at(i) != s.at(s.size() - i) )
		{
			cnt++;
		}
	}
	/*for(int i = 1; i <= n; i++)
	{
		int b = p[i].first - p[n + 1 - i].first;
		if(b != 0)
		{
			 
		}
	}*/
	cout << cnt;
	
	return 0;
}

