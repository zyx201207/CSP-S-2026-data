#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
string t;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2)
	{
		t += "1";
		if(s1.substr(0,2) == s2.substr(0,2))
		{
			t+="1";
			s1.erase(0,2);
			s2.erase(0,2);
			if(s1 == "A" || s1 == "B" || s1 == "C" && s2 == "A" || s2 == "B" || s2 == "C")
			{
				t += "1";
				if(s1 == "A" && s2 == "B")
				{
					t+="1";
					cout << t;
					return 0;
				}
				else if(s1 == "B" && s2 == "C")
				{
					t+="1";
					cout << t;
					return 0;
				}
				else if(s1 == "B" && s2 == "A")
				{
					t+="1";
					cout << t;
					return 0;
				}
				else if(s1 == "C" && s2 == "B")
				{
					t+="1";
					cout << t;
					return 0;
				}
				else
				{
					t += "0";
					cout << t;
					return 0;
				}
			}
			else if(s1 == "D" || s1 == "F" && s2 == "D" || s2 == "F")
			{
				t += "1";
				t += "1";
				cout << t;
				return 0;
			}
			else
			{
				cout << "1100";
				return 0;
			}
		}
		else
		{
			cout << "1000";
			return 0;
		}
	}
	else
	{
		cout << "0000";
		return 0;
	}
} 
