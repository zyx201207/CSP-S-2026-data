#include<bits/stdc++.h>
using namespace std;
bool check1(string s , string t)
{
	bool flag1 = false , flag2 = false;
	if(s[2] == 'D' || s[2] == 'F')
		flag1 = true;
	if(t[2] == 'D' || t[2] == 'F')
		flag2 = true;
	return (flag1 == flag2);
}
bool check2(string s , string t)
{
	if((s[2] == 'D' && t[2] == 'F') || (s[2] == 'F' && t[2] == 'D'))
		return true;
	if((s[2] == 'A' && t[2] == 'B') || (s[2] == 'B' && t[2] == 'C'))
		return true;
	return false;
}
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) 
		cout << "1";
    else 
	{
		cout << "0000";
		return 0;
	}
    if(s1[0] == s2[0] && s1[1] == s2[1])
		cout << "1";
	else
	{ 
		cout << "000";
		return 0;
	}
	if(check1(s1 , s2))
		cout << "1";
	else
	{
		cout << "00";
		return 0;
	}
	if(check2(s1 , s2))
		cout << "1";
	else
		cout << "0";
	return 0;
}

