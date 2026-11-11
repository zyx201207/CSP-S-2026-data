#include <bits/stdc++.h>
using namespace std;
long long n , sum , num , ans;
string s;
int main()
{
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin >> n;
	bool q = 1;
	long long w , a;
	while(n--)
	{
		char c;
		cin >> a >> c;
		for(long long i = 1;i <= a;i++)
			s += c;
		sum += a;
	}
	s = ' ' + s;
	for(long long i = 1;i <= sum/2;i++)
		if(s[i] != s[sum + 1 - i])
			num ++;
	for(long long i = sum/2 + 1;i <= sum;i++)
		if(s[i] != s[sum + 1 - i])
			ans++;
	cout << min(num , ans);
	return 0; 
}
