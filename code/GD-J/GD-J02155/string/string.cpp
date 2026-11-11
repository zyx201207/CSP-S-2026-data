#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin >> n;
	string hui = "";
	for(int i = 1;i <= n;i++)
	{
		long long a;
		cin >> a;
		char c;
		cin >> c;
		for(int j = 1;j <= a;j++)
		{
			hui = hui + c;
		}
	}
	
	
	bool wen = true;
	for(int i = 0;i < hui.length();i++)
	{
		if(hui[i] != hui[hui.length() - i - 1])
		{
			bool wen = false;
		}
	}
	if(wen)
	{
		cout << 0;
	}
	else
	{
		cout << 2;
	}
 } 
