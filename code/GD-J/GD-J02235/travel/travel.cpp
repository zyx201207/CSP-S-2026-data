#include<bits/stdc++.h>
using namespace std;
string c_1, s_1, c_2, s_2;
string a, b;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if (c_1 == c_2)
	{
		printf("1");
	}
	else
	{
		printf("0000");
		return 0;
		
	}
	for (int i = 0; i < s_1.size() - 1; i++)
	{
		a += s_1[i];
	}
	for (int i = 0; i < s_2.size() - 1; i++)
	{
		b += s_2[i];
	}
	if (a == b)
	{
		printf("1");
	}
	else
	{
		printf("000");
		return 0;
		
	}
	a = b = "";
	
	if ((s_1[2] == 'A' || s_1[2] == 'B' || s_1[2] == 'C') && (s_2[2] == 'A' || s_2[2] == 'B' || s_2[2] == 'C'))
	{
		printf("1");
	}
	else if ((s_1[2] == 'D' || s_1[2] == 'F') && (s_2[2] == 'D' || s_2[2] == 'F'))
	{
		printf("1");
	}
	else
	{
		printf("00");
		return 0;	
	}
	
	if (char(s_1[2] - 1) == s_2[2] || char(s_1[2] + 1 ) == s_2[2])
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	return 0;
}
