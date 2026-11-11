#include<bits/stdc++.h>
using namespace std ;
int a , b , a2 , b2 ;
char A , B ;
bool xi (  )
{
	if ( a == b && a != 01 && a != 16 )
	{
		return 1 ;
	}
	return 0 ;
}
bool pai ()
{
	if ( a2 == b2 )
	{
		return 1 ;
	}
	return 0 ;
}
bool qe ()
{
	if ( pai() )
	{
		if ( ( a2 == b2 ) && ( ( A <= 'C' && A >= 'A' && B <= 'C' && B >= 'A' ) || ( A <= 'F' && A >= 'D' && B <= 'F' && B >= 'D' ) ) )
		{
			return 1 ;
		}
	}
	return 0 ;
}
bool xianl ()
{
	if ( xi () )
	{
		if ( pai () )
		{
			if ( qe() )
			{
				if ( ( A == 'D' && B == 'F' ) || ( A == 'F' && B == 'D' || ( A + 1 == B ) || ( B + 1 == A ) ) )
				{
					return 1 ;
				}
			}
		}
	}
	return 0 ;
}
int main ()
{
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	cin >> a >> a2 >> A >> b >> b2 >> B ;
	if ( xi() )
	{
		cout << 1 ;
	}
	else
	{
		cout << "0000" ;
		return 0 ;
	}
	if ( pai() )
	{
		cout << 1 ;
	}
	else
	{
		cout << 0 ;
	}
	if ( qe() )
	{
		cout << 1 ;
	}
	else
	{
		cout << 0 ;
	}
	if ( xianl () )
	{
		cout << 1 ;
	}
	else
	{
		cout << 0 ;
	}
	return 0 ;
	
}
