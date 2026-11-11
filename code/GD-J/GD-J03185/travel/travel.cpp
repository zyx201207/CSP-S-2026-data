#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	long long len1 = s1.size();
	long long len2 = s2.size();
	if(len1 == len2)
	{
		if(len1 == 4)
		{
			if(s1[1] == s2[1] && s1[2] == s2[2]) cout << 1;
			else 
			{
				cout << "000";
				return 0;
			}
		}
		else
		{
			if(s1[1] == s2[1]) cout << 1;	
			else
			{
				cout << "000";
				return 0;
			}
		}
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(len1 == 3)
	{
		if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
		{
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') cout << 1;
			else 
			{
				cout << "00";
				return 0;
			}
		}
		else
		{
			if(s2[2] == 'D' || s2[2] == 'F') cout << 1;
			else 
			{
				cout << "00";
				return 0;
			}
		}
	}
	else 
	{
		if(s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C')
		{
			if(s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C') cout << 1;
			else 
			{
				cout << "00";
				return 0;
			}
		}
		else
		{
			if(s2[3] == 'D' || s2[3] == 'F') cout << 1;
			else 
			{
				cout << "00";
				return 0;
			}
		}
	}
	if(len1 == 3)
	{
		if(s1[2] == 'A' && s2[2] == 'B') cout << 1;
		else if(s1[2] == 'B' && s2[2] == 'A') cout << 1;
		else if(s1[2] == 'B' && s2[2] == 'C') cout << 1;
		else if(s1[2] == 'C' && s2[2] == 'B') cout << 1;
		else if(s1[2] == 'D' && s2[2] == 'F') cout << 1;
		else if(s1[2] == 'F' && s2[2] == 'D') cout << 1;
		else cout << 0;
	}
	else 
	{
		if(s1[3] == 'A' && s2[3] == 'B') cout << 1;
		else if(s1[3] == 'B' && s2[3] == 'A') cout << 1;
		else if(s1[3] == 'B' && s2[3] == 'C') cout << 1;
		else if(s1[3] == 'C' && s2[3] == 'B') cout << 1;
		else if(s1[3] == 'D' && s2[3] == 'F') cout << 1;
		else if(s1[3] == 'F' && s2[3] == 'D') cout << 1;
		else cout << 0;
	}
	return 0;
}
