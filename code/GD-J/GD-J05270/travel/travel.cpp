#include <iostream>
using namespace std;


int main()
{
	int c1,c2;
	char s11,s12,s13,s21,s22,s23;
	cin >> c1 >> s11 >> s12 >> s13 >> c2 >> s21 >> s22 >> s23;
	if(c1 == c2)
	{cout << "1";}
	else
	{cout << "0";}
	if(s11 == s21 && s12 == s22)
	{cout << "1";}
	else
	{cout << "0";}
	if((s13 <= 'C' && s23 <= 'C') || (s13 >= 'D' && s23 >= 'D'))
	{
		if(s13 - s23 == -1 || s13 - s23 == 1)
		{
		cout << "11";}
		else
		{
		cout << "10";}
	}
	else
	cout << "00";
	return 0;
 } 
