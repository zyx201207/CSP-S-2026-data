#include <iostream>
using namespace std ;
string name = "travel" ;
bool debug = 0 ;//要调0！
inline int s2l(string s)
{
	return s[0] - '0' * 10 + s[1] - '0' ;
}
inline int s2p(string s)//ABC DF对应123 56 
{
	if(s[2] == 'D')
		return 5 ;
	return s[2] - 'A' + 1 ;
}
int main()
{
	if(!debug)
	{
		string inname = name + ".in" ;
		string outname = name + ".out" ;
		freopen(inname.c_str() , "r" , stdin) ;
		freopen(outname.c_str() , "w" , stdout) ;
	}
	int c1 , c2 ;
	string s1 , s2 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	int l1 = s2l(s1) , l2 = s2l(s2) ;
	int p1 = s2p(s1) , p2 = s2p(s2) ;
	if(c1 != c2)
	{
		cout << "0000\n" ;
		return 0 ;
	}
	cout << 1 ;
	if(l1 != l2)
	{
		cout << "000\n" ;
		return 0 ;
	}
	cout << 1 ;
	if(!((p1 <= 3 && p2 <= 3) || (p1 >= 5 && p2 >= 5)))
	{
		cout << "00\n" ;
		return 0 ;
	}
	cout << 1 ;
	if(p1 - p2 == 1 || p1 - p2 == -1)
		cout << "1\n" ;
	else
		cout << "0\n" ;
	return 0 ;
}
//yee~ 
