#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt = 0,ans = 1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char a;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x >> a;
		for(int i = 1;i <= x;i++)
		{
			s = s + a;
		}
	}
	int l = 0,r = s.size()-1;
	while(l < r)
	{
		if(s[l] != s[r])
		{
			cnt++;
		}
		r--;
		l++;
	}
	cout << cnt;
	return 0;
}
