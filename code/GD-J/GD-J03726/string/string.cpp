#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
map<int, int> s;
int scnt = 1;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	while (n--)
	{
		int x;
		char a;
		
		cin >> x;
		cin >> a;
		
		for (int i = 1; i <= x; i++)
		{
			s[scnt++] = a;
		}
	}
	int len = scnt;
	int answer = 0;
	
	//cout << len << ' ';
	
	for (int i = 1, j = len - 1; j >= i; i++, j--)
	{
		//cout << s[i] << ' ';
		//	cout << "i =" << s[i] << ' ' << s[j] << i << ' ' << j << endl;
		if (s[i] != s[j]) 
		{
			answer++;
		}
	}
	cout << answer;
	return 0;
}
