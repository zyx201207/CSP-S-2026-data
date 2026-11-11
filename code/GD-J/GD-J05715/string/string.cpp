#include<bits/stdc++.h>
using namespace std;
int hui(string s)
{
	long long cnt = 0;
	string x = "";
	for(int i = 0; i <= s.size()/2; i++)
	{
		x += s[i];
	}
	//cout << x << endl;
	long long c = x.size();
	for(long long i = s.size()-1; i >= c; i--)
	{
		x += x[i-c];
	}
	//cout << x << endl;
	for(long long i = 0; i < s.size(); i++)
	{
		if(s[i] != x[i])
		{
			//cout << s[i] << endl;
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	while(n--)
	{
		long long x;
		cin >> x;
		string a;
		cin >> a;
		for(int i = 1; i <= x; i++)
		{
			s += a;
		}
		
	}
	cout << hui(s);
} 
