#include<bits/stdc++.h>
#define itn int
#define cotu cout
#define fro for
using namespace std;
int n,sum = 0,num = 0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int x1;
		char y1;
		cin >> x1 >> y1;
		num += x1;
		for (int j = 1;j <= x1;j++)
		{
			s += y1;
		}
	}
	int x,y;
	if (num%2 == 0)
	{
		x = num/2-1;
		y = num/2;
	}
	else
	{
		x = num/2-1;
		y = num/2+1;
	}
	while(x >= 0 || y <= num)
	{
		if (s[x] != s[y])
		{
			sum++;
		}
		x--;
		y++;
	}
	cout << sum;
	return 0;
}

/*
3
2 a
2 b
1 c

2
2 a
2 b

2
2 a
3 a

*/
