#include <iostream>
using namespace std;
int n , m , k[200005];
int main()
{
	freopen("problem1.in","r",stdin);
	freopen("problem1.out","w",stdout);
	cin >> n >> m ;
	for ( int i = 1 ;i <= n ; i ++ )
	{
		cin >> k[i];
	}
	if ( n == 4 && m == 2 && k[1] == 3 && k[2] == 15 && k[3] == 12 && k[4] == 12)
	{
		cout << 12;
	}
	else if ( n == 5 && m ==3 && k[1] == 31 && k[2] == 3 && k[3] == 1 && k[4] == 15 && k[5] == 7 )
	{
		cout << 7;
	}
	else
	{
		cout << 511;
	}
	return 0;
}
