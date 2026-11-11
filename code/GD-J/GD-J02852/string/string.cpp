#include <bits/stdc++.h>
using namespace std;
int n , a[200005] ;
char c[200005];
//·´×ª£ºreserve; 
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w", stdout);
	string s;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] >> c[i];
	long long sum = 0;
	for(int i = 1 ; i <= n;i++)
	{
		for(int j = 1 ; j <= a[i] ; j++)
		{
			s += c[i];	
			sum++;
		}
	}
	int minn = 0 , cnt = 0;
	for(int i = 1 ; i <= sum / 2; i++)
	{
		if(s[i - 1] != s[sum - i])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
