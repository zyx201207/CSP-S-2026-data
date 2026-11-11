#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int aT ,bT;
char aN[5] , bN[5];
int L[10] = {0 , 0 , 0 , 1 , 1};
int Q[10] = {1 , 2 , 3 , 5 , 6};
int c1 , c2 ,c3 ,c4;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> aT >> aN >> bT >> bN;
	if(aT == bT)
	{
		c1 = 1;
	}
	else
	{
		c1 = 0;
	}
	if(c1 && aN[0] == bN[0] && aN[1] == bN[1])
	{
		c2 = 1;
	}
	else
	{
		c2 = 0;
	}
	if(c2 && L[aN[2] - 'A'] == L[bN[2] - 'A'])
	{
		c3 = 1;
	}
	else
	{
		c3 = 0;
	}
	if(c3 && (Q[aN[2] - 'A'] - Q[bN[2] - 'A'] == 1 || Q[aN[2] - 'A'] - Q[bN[2] - 'A'] == -1))
	{
		c4 = 1;
	}
	else
	{
		c4 = 0;
	}
	cout << c1 << c2 << c3 << c4;
	return 0;
} 
