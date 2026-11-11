#include<bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;
map<char, int> mp;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	mp['A'] = 1;
	mp['B'] = 2;
	mp['C'] = 3;
	mp['D'] = 6;
	mp['F'] = 7;
	
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2)
	{
		cout<<"0000";
		return 0;
	}
	string x1, x2;
	x1 = s1[0]+s1[1];
	x2 = s2[0]+s2[1];
	
	if(x1 != x2)
	{
		cout<<"1000";
		return 0;
	}
	int y1 = mp[s1[2]], y2 = mp[s2[2]];
	if(abs(y1-y2) > 2)
	{
		cout<<"1100";
		return 0;
	}
	if(abs(y1-y2) != 1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	
	return 0;
}
