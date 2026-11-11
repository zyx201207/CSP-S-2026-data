#include <bits/stdc++.h>
using namespace std;

bool isValid(string A, string B)
{
	if(A == "A" || A == "B" || A == "C")
	{
		if(B == "A" || B == "B" || B == "C")
			return true;
			
		else
			return false;
	}
	
	else
	{
		if(B == "D" || B == "F")
			return true;
			
		else
			return false;
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string cf, sf, cs, ss;
	cin >> cf >> sf >> cs >> ss;
	
	if(cf == cs)
	{
		cout << 1;
		string A = sf.substr(2);
		string B = ss.substr(2);
		
		if(sf.substr(0, 2) == ss.substr(0, 2))
		{
			cout << 1;
			if(isValid(A, B))
			{
				cout << 1;
				if(A == "D" || A == "F" || A == "B" || B == "B")
					cout << 1;
					
				else
					cout << "0";
			}
			
			else
				cout << "00";
		}
		
		else
			cout << "000";
	}
	
	else 
		cout << "0000";
	return 0;
}
