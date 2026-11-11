#include <bits/stdc++.h>
using namespace std ;
string str ;
char z1[10005] ;
char z2[10005];
int main ()
{
	freopen ("string.in" , "r" , stdin) ;
	freopen ("string.out" , "w" , stdout) ;
	int n ;
	cin >> n ;
	for (int i=0 ; i < n ; i += 1)
	{
		int c ;
		cin >> c ;
		char s ;
		cin >> s ;
		for (int j = 0; j  < c ; j += 1)
		{
			str += s ;
		}
	}


	if (str.size() % 2 == 0)
	{
		int d = str.size() / 2 ;
		for (int i = 0  ;  i <= d ; i  += 1)
		{
			z1[i] = str[i] ;
		}
		for (int i = d ; i <=  str.size() ; i += 1)
		{
			z2[i- d] = str[i] ;
		}
		int num = 0;
		for (int i = 0 ; i < d ; i += 1)
		{
			if (z1[i] != z2[i])
			{
				num += 1 ;
			}
		}
		cout << num;


	}


	if (str.size() % 2 != 0)
	{
		int d = str.size() / 2 ;
		for (int i = 0  ;  i <= d ; i  += 1)
		{
			z1[i] = str[i] ;
		}
		for (int i = d + 1 ; i <=  str.size() ; i += 1)
		{
			z2[i- d - 1] = str[i] ;
		}
		int num = 0;
		for (int i = 0 ; i < d ; i += 1)
		{
			if (z1[i] != z2[i])
			{
				num += 1 ;
			}
		}
		cout << num;


	}
	return 0  ;





}
