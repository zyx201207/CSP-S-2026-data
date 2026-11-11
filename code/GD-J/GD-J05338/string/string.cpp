#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin >> n;
	string s;
	for(int i = 1;i <= n;i++)
	{
		long long p;
		string q;
		cin >> p >> q;
		for(int j = 1;j <= p;j++)
		{
			s += q;
		}
	}
	long long l = 0,r = s.size() - 1,cnt = 0;
	while(r >= l)
	{
		if(s[r] != s[l])
			cnt++;
		r--;
		l++; 
	}
	cout << cnt;
	return 0;
}
