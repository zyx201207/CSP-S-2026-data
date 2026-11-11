#include <bits/stdc++.h>
using namespace std;
string s,s1;
long long  x ,n;
long long check()
{
	long long y = 0;
	for(int i = 0 ; i <= s.size()/ 2 - 1;i++)
	{
		if(s[i] != s[s.size() - i - 1]) y ++;
	}
	return y;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	s = "";
	for(long long  i = 1 ; i<=n ; i++)
	{
		cin >>x >> s1;
		for(long long  j = 1 ; j <= x; j ++)
		{
			s += s1;
		}
	}
	cout << check();
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
