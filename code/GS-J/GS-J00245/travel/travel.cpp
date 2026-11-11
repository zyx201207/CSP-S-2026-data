#include<bits/stdc++.h>
using namespace std;
bool pd1 = 0 , pd2 = 0 , pd3 = 0 , pd4 = 0;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2)
	{
		pd1 = 1;
	}
	
	if(pd1)
	{
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			pd2 = 1;
		}
	}
	
	if(pd1 && pd2)
	{
		bool temp1 = 0 , temp2 = 0;
		if(s1[2] == 'D' || s1[2] == 'F')
		{
			temp1 = 1;
		}
		if(s2[2] == 'D' || s2[2] == 'F')
		{
			temp2 = 1;
		}
		if(temp1 == temp2)
		{
			pd3 = 1;
		}
	}
	
	if(pd1 && pd2 && pd3)
	{
		int temp1 , temp2;
		
		if(s1[2] == 'A')
		{
			temp1 = 1; 
		}
		if(s1[2] == 'B')
		{
			temp1 = 2;
		}
		if(s1[2] = 'C')
		{
			temp1 = 3;
		}
		if(s1[2] == 'D')
		{
			temp1 = 4;
		}
		if(s1[2] == 'E')
		{
			temp1 = 5;
		}
		
		if(s2[2] == 'A')
		{
			temp2 = 1;
		}
		if(s2[2] == 'B')
		{
			temp2 = 2;
		}
		if(s2[2] == 'C')
		{
			temp2 = 3;
		}
		if(s2[2] == 'D')
		{
			temp2 = 4;
		}
		if(s2[2] == 'E')
		{
			temp2 = 5;
		}
		
		if(abs(temp1 - temp2) == 1)
		{
			pd4 = 1;
		}
	}
	
	cout << pd1 << pd2 << pd3 << pd4;
	return 0;
}
//¹µÊÂ´úÂë 
