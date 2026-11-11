#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1>> s1 >> c2 >> s2;
	bool T ,T2;
	if(c1 == c2)
	{
		cout << "1";
	}
	if(c1 != c2)
	{
		cout << "0";
	}
	if(s1[1] == s2[1]&& s1[2] == s2[2])
	{
		cout << "1";
	}
	if(s1[1] != s2[1]&& s1[2] == s2[2])
	{
		cout << "0";
	}
	if(s1[1] == s2[1]&& s1[2] != s2[2])
	{
		cout << "0";
	}
	if((s1[3] == 'A' ||s1[3] == 'B' || s1[3] == 'C')&&(s2[3] == 'D'||s2[3] == 'F'))
	{
		T = false;
	}
	if((s1[3] == 'D' ||s1[3] == 'F' || s2[3] == 'A')&&(s2[3] == 'B'||s2[3] == 'C'))
	{
		T = false;
	}
    if((s1[3] == 'A' ||s1[3] == 'B' || s1[3] == 'C')&&(s2[3] == 'A'||s2[3] == 'B'|| s2[3] == 'C'))
	{
		T = true;
	}
	if((s1[3] == 'D' ||s1[3] == 'F') &&( s2[3] == 'D'||s2[3] == 'F'))
	{
		T = true;
	}
	if(s1[3]-'A'+1 == s2[3]-'A')
	{
		T2 = true;
	}
	if(s2[3]-'A'+1 == s1[3]-'A')
	{
		T2 = true;
	}
	else
	{
		T2 = false;
	}
     cout << T << T2;
	return 0;
 } 
