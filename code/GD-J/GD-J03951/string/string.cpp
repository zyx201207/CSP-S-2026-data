#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,sum = 0,num = 0;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		long long a;
		string b;
		cin >> a >> b;
		num+=a;
		for(int i = 1;i <= a;i++)
		{
			s += b;
		}
	}
	for(int i = 0;i < num/2;i++)
	{
		if(s[i] != s[num-i-1])
		{
			sum++; 
		}
	}
	cout << sum;
	return 0;
}
