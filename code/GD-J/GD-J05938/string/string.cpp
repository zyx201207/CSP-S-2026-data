#include<bits/stdc++.h>
using namespace std;
long long n,scnt = 0, cnt = 0;
string s;
int check(string s)
{
	int l = 1, r = scnt;
	for(int i = l; i <= r; i++)
	{
		if(s[l] == s[r])
		{
			l++;
			r--;
		}
		else 
		{
			l++;
			r--;
			cnt++;
		}
		cout << l << r << cnt << endl;
	}
	return cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		long long x;
		string s1;
		cin >> x >> s1;
		scnt += x;
		for(long long j = 1; j <= x; j++) s += s1;
	}
	cout << check(s);
	return 0;
}
