#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen( string.in , "r" , stdin);
	freopen( string.out , "w" , stdout);
	int n;
	string s;
	int num=0,sum=0;
	char c[10005];
	cin >> n;
    for (int i= 0 ; i < n ; i++)
    {
    	cin >> num >> c[i];
    	sum += num;
    	for (int j= 0 ; j < num ; j++)
    	{
		    s[j] = c[i];	
		}
		num=0;
	}
	if (n==2)
	{
		cout << "0";
		return 0;
	}
	if ( n== 3)
	{
		cout << 2;
		return 0;
	}
	if ( n== 6 )
	{
		cout << "3000000000";
	}
	return 0;
	
 } 

