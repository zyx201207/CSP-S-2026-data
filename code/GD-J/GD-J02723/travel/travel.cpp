#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)cout << 1;
	else 
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	char t1 = s1[2],t2 = s2[2];
	int hang1 = (s1[0] - '0')*10 + s1[1] - '0'; 
	int hang2 = (s2[0] - '0')*10 + s2[1] - '0'; 
	if(hang1 == hang2)
	{
		cout << 1;
		if('A' <= t1 && t1 <= 'C' && 'A' <= t2 && t2 <= 'C')
		{
			cout << 1;
			if(abs(t1 - t2) == 1)cout << 1;
			else cout << 0;
		}
		else if('D' <= t1 && t1 <= 'E' && 'D' <= t2 && t2 <= 'E')
		{
			cout << 1;
			if(abs(t1 - t2) == 1)cout << 1;
			else cout << 0;
		}
		else cout << 0 << 0;
	}
	else cout << 0 << 0 << 0;
	return 0;
}
