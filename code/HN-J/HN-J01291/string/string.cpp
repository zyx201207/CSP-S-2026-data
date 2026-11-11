#include <bits/stdc++.h> 
using namespace std;
long long n,a;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a >> c;
		for(int j = 0;j < a;j++)
		{
			s += char(c);
		}
	}
	long long sum = 0,l = 0,r = s.size()-1,flag = 0;
	while(l <= r)
	{
		if(s[l] != s[r])
		{
			sum++;
		}
		l++;
		r--;
	}
	cout << sum;
	return 0;
}
