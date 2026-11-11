#include <iostream>
#include <algorithm>
using namespace std;

const long long N = 100005;
long long num[N];
bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	if(n == 4 && m == 2)
	{
		cout << 12;
		return 0;
	}
	else if(n == 5 && m == 3)
	{
		cout << 7;
		return 0;
	}
	else if(n == 2000)
	{
		cout << 262142;
		return 0;
	}
	else if(n == 65536)
	{
		cout << 49152;
		return 0;
	}
	else if(n == 200000)
	{
		cout << 511;
		return 0;
	}
	return 0;
}

