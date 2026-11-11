#include<bits/stdc++.h>

using namespace std;
string c1 , s1 , c2 , s2 , s11 , s12 , s21 , s22;
bool a1 , a2 , a3 , a4;

int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0;i < s1.size(); i++)
	{
		if(s1[i] >= '0'&&s1[i] <= '9')
			s11 += s1[i];
		if(s1[i] >= 'A'&&s1[i] <= 'Z')
			s12 += s1[i];
	}
	for(int i = 0;i < s2.size(); i++)
	{
		if(s2[i] >= '0'&&s2[i] <= '9')
			s21 += s2[i];
		if(s2[i] >= 'A'&&s2[i] <= 'Z')
			s22 += s2[i];
	}
	if(c1 == c2)
	{
		a1 = 1;
		if(s11 == s21)
		{
			a2 = 1;
			{
				if(s12 >= "A" && s12 <= "C" && s22 >= "A" && s22 <= "C") 
				{
					a3 = 1;	
					if(s12 == "A" && s22 == "B" ||s12 == "C" && s22 == "B" ||s22 == "A" && s12 == "B" ||s22 == "C" && s12 == "B")
						a4 = 1;
				}
				else if(s12 >= "D" && s12 <= "F"&&s22 >= "D" && s22 <= "F")
				{
					a3 = 1;
					a4 = 1;
				}
			}
		}
	}
	cout << a1 << a2 << a3 << a4;
	return 0;
}
