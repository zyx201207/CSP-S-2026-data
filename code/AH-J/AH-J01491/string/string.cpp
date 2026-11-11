#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
 	int a,n,num = 0;
 	string s;
 	string c; 
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		num += a; 
		for (int i = 1;i <= a;i++)
		{
			s += c;
		}
	}
	string m;
	for (int i = num - 1;i >= 0;i--) 
	{
		m += s[i];
	}
	int sum = 0;
	for (int i = 0;i < num;i++)
	{
		if (s[i] != m[i]) sum++;
	}
	cout << sum;
	return 0;
}
