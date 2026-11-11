#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);//²¹È« 
	long long n;
	cin >> n;
	string s;
	for(int i = 1;i <= n;i++)
	{
		long long m;
		cin>>m;
		char h;
		cin >> h;
		for(int i = 1;i <= m;i++)
		{
			s += h;
		}
	}
	bool pp = 0;
	long long eos = 0;
	
		long long dd = s.length() / 2 - 1;

	long long ddd = (s.length()) - 1;
		for(int j = 0;j <= dd;j++)
		{
			if(s[j] != s[ddd - j]){
				eos++;
				pp = 1;
			}
		}
		if(pp == 0 && s[dd + 1] == s[0])
		{
			cout << 0;
			return 0;
		}
	cout << eos;
	return 0;
}
