#include <iostream>
#include <string>
using namespace std;

string hws(string ss)
{
	string s2;
	for(int i = 1; i <= ss.size(); i++)
	{
		s2 += ss[ss.size() - i];
	} 
	return s2;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,sf,sl;
	int n;
	cin >> n; 
	for(int i = 1; i <= n; i++)
	{
		int a;
		char b; 
		cin >> a >> b;
		for(int j = 1; j <= a; j++)
		{
			s += b;
		}
	}
	cout << s << endl;
	if(s == hws(s))
	{
		cout << "0" << endl;
		return 0;
	}
	for(int i = 0; i < s.size() / 2; i++)
	{
		sf += s[i];
	}
	for(int i = (s.size() / 2) + (s.size() % 2); i < s.size(); i++)
	{
		sl += s[i];
	}
	sl = hws(sl);
	int g = 0;
	for(int i = 0; i < sf.size(); i++) 
	{
		if(sf[i] != sl[i])
		{
			g++;
		}
	}
	cout << g << endl;
	return 0;
}
