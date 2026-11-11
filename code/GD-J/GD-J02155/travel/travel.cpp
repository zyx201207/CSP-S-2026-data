#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
		
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	
	if(s1[1] == s2[1] )
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	
	bool you1 = true;
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
	{
		bool you1 = true;
	}
	else 
	{
		bool you1 = false;
	}
	bool you2 = true;
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
	{
		bool you2 = true;
	}
	else 
	{
		bool you2 = false;
	}
	if(you1 == you2)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	
	if(you1 != you2)
	{
		cout << "0";
	}	
	else if(you1 == false && you2 == false)
	{
		cout << "1";
	}
	else if(s1[2] == 'B' || s2[2] == 'B')
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	
	return 0;
	

 } 
