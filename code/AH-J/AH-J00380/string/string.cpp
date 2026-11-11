#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	int a[100000];
	char b[100000];
	char c[1000000];
	char d1;
	int c1 = 1;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	for(int i = 1;i <= n;i++)
	{
		if(b[i] == d1)
		{
			c1 = 0;
		}
		else if(b[i] != d1)
		{
			c1 = 3;
			break;
		}
	}
	cout << c1 << endl;
	return 0;
}
