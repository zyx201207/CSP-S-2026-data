#include <iostream>
using namespace std;

int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	int c1 , c2;
	char a[5] , b[5]; 
	cin >> c1 >> a >> c2 >> b;
	int numa = 10*(a[0]-'0') + (a[1]-'0');
	int numb = 10*(b[0]-'0') + (b[1]-'0');
	char s1 = a[2] , s2 = b[2];
	if (s1 == 'F')
		s1 == 'E';
	if (s2 == 'F')
		s2 == 'E';
	
//	cout << s1 + 1<< " kkk " << (int)s2 << '\n';
	
	if (c1 != c2)
	{
		cout << "0000" <<'\n';
	}
	else if (numa != numb)
	{
		cout << "1000" <<'\n';
	}
	else if (!((s1 >= 'D' && s2 >= 'D') || (s1 < 'D' && s2 < 'D')))
	{
		cout << "1100" <<'\n';
	}
	else if (!(((int)(s1+1) == (int)s2) || ((int)(s2+1) == (int)s1)))
	{
		cout << "1110" <<'\n';
	}
	else
	{
		cout << "1111" <<'\n';
	}
	return 0;
}
