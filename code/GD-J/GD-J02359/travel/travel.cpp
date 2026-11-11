#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans = "0000";
bool checkCD(char x,char y){return (x == 'C' && y == 'D') || (x == 'D' && y == 'C');}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << ans;
		return 0;
	}
	ans[0] = '1';
	if(s1[0] == s2[0] && s1[1] == s2[1])
	{
		ans[1] = '1';
		if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
		{
			ans[2] = '1';
			
			if(abs(s1[2] - s2[2]) == 1 && !checkCD(s1[2],s2[2]))ans[3] = '1';
		}
	}
	
	if(s1[2] == s2[2])
	{
		int x = (s1[0] - '0') * 10 + (s1[1] - '0');
		int y = (s2[0] - '0') * 10 + (s2[1] - '0');
		
		if(abs(x - y) == 1)ans[3] = '1';
	}
	cout << ans;
	return 0;
}
