#include<iostream>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c2,s2;
	cin >> c >> s >> c2 >> s2;
	string x = "",x2 = "";
	for(int i = 0; i < s.size(); i ++ )
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			x += s[i];
		}
	}
	for(int i = 0; i < s2.size(); i ++ )
	{
		if(s2[i] >= '0' && s2[i] <= '9')
		{
			x2 += s2[i];
		}
	}
	if(c == c2)
	{
		cout << "1";
		if(x == x2)
		{
			cout << "1";
			if((s[s.size() - 1] < 'D' && s2[s2.size() - 1] < 'D') || (s[s.size() - 1] >= 'D' && s2[s2.size() - 1] >= 'D'))
			{
				cout << "1";
				char ch = s[s.size() - 1],ch2 = s2[s2.size() - 1];
				if(ch + 1 == ch2 || ch2 + 1 == ch) cout << "1";
				else if((ch == 'D' && ch2 == 'F') || (ch == 'F' && ch2 == 'D')) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
