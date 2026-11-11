#include<bits/stdc++.h>
using namespace std;

bool check(char a,char b)
{
	if((a == 'A'&& b == 'B')||(a == 'B'&& b == 'A'))
		return true;
	if((a == 'B'&& b == 'C')||(a == 'C'&& b == 'B'))
		return true;
	if((a == 'D'&& b == 'F')||(a == 'F'&& b == 'D'))
		return true;
	return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2,ans = "";
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0] == c2[0]&&c1[1] == c2[1])
	{
		ans += "1";
		if(s1[0] == s2[0]&&s1[1] == s2[1])
		{
			ans += "1";
			int x,y;
			if(s1[2] == 'D'||s1[2] == 'F')
				x = 1;
			else
				x = 2;
			if(s2[2] == 'D'||s2[2] == 'F')
				y = 1;
			else
				y = 2;
			if(x == y)
			{
				ans += "1";
				if(check(s1[2],s2[2]))
				{
					ans += "1";
				}
				else
					ans = "1110";
			}
			else
				ans = "1100";
		}
		else
			ans = "1000";
	}
	else
		ans = "0000";
	cout << ans;
	return 0;
}
