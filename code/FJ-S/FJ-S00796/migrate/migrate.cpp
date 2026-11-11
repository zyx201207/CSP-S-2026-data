#include <iostream>
using namespace std ;
string name = "migrate" ;
bool debug = 0 ;//上交时为0！
int main()
{
    if(!debug)
	{
		string inname = name + ".in" ;
		string outname = name + ".out" ;
		freopen(inname.c_str() , "r" , stdin) ;
		freopen(outname.c_str() , "w" , stdout) ;
	}
	return 0 ;
}
//yee~

