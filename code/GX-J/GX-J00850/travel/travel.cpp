#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s1,c1,s2,c2;


bool solve1()
{
	if (c1 == c2)
	{
		return true;
	}
	return false;
}

bool solve2()
{
	if (solve1())
	{
		string sum1 = "";
		sum1 += s1[0];
		sum1 += s1[1];
		string sum2 = "";
		sum2 += s2[0];
		sum2 += s2[1];
		
		if (sum1 == sum2)
		{
			return true;
		}
		return false;
	}
	else 
	{
		return false;
	}
}
	

bool solve3()
{
	if (solve2())
	{
		if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C')
		{
			return true;
		}
		else if (s1[2] >= 'E' && s1[2] <= 'F' && s2[2] >= 'E' && s2[2] <= 'F')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool solve4()
{
	if (solve3())
	{
		if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A'))
		{
			return true;
		}
		else if ((s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'))
		{
			return true;
		}
		else if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	else
	{
		return false;
	}
	
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	

	cin >> c1 >> s1 >> c2 >> s2;
	
	if (solve1())
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	
	if (solve2())
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	
	if (solve3())
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	
	if (solve4())
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}
