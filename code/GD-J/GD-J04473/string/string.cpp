#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	FILE* read_file = freopen("string.in", "r", stdin);
	FILE* write_file = freopen("string.out", "w", stdout);
	int n;
	string s = "";
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++)
		{
			s += c;
		}
	}
	//cout << "Now string:" << s << endl;
	int l = s.length();
	int r = (l - 1) / 2;
	int left;
	long long sum = 0;
	if(l % 2 == 0)
	{
		left = r;
	}
	else
	{
		left = r - 1;
	}
	for(int i = r; i < l; i++)
	{
		if(i > r)
		{
			//cout << "left = " << left << ",i = " << i << endl;
			if(s[left] != s[i])
			{
				sum++;
			}
			left--;
		}
	}
	cout << sum;
	return 0;
}
