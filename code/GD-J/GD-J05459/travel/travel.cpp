#include<iostream>
using namespace std;
int main()
{
	stdin("travel.in","r","stdin");
	stdin("travel.out","w","std.out");
	int c1,c2;
	string s1,s2;
	
	bool flag = true;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1==c2);
	flag = (c1==c2);
	int a1 = 0,a2 = 0;
	char ss1,ss2;
	for(auto c : s1)
	{
		if(c >= '0' && c <= '9') a1 = a1 * 10 + int(c - '0');
		else ss1 = c;
	}
	for(auto c : s2)
	{
		if(c >= '0' && c <= '9') a2 = a2 * 10 + int(c - '0');
		else ss2 = c;
	}
	cout << (a1 == a2 && flag);
	flag = ((a1 == a2) && flag);
	if(((ss1 <= 'C' && ss2 <= 'C')||(ss1 >= 'D' && ss2 >= 'D')) && flag)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
		flag = false;
	}
	if(abs(ss1-ss2) == 1 && flag)
		cout << 1;
	else
		cout << 0;
	return 0;
} 
