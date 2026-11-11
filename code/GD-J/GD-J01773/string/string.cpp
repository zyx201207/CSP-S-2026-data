#include <bits/stdc++.h>
using namespace std;
vector<char> v;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >>n;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		char b;
		int a;
		cin >> a >>b;
		for(int i =1;i <= a;i++)
		{
			v.push_back(b);
		}
		ans += a;
		  
	}
	int num = 0;
	if(ans % 2 == 0)
	{
		for(int i =0;i < ans/2;i++)
		{
			if(v[i] != v[ans-i-1])
			{
				num++;
			}
		}
	}
	else
	{
		for(int i = 0;i < ans/2+1;i++) 
		{
			if(v[i] != v[ans-i-1])
			{
				num++;
			}
		}
	}
	cout << num;
	return 0;
}
