#include <bits/stdc++.h>
using namespace std;
string s;
int n,x,ans,num;
char y; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> x >> y;
		for (int j = 1;j <= x;j++) 
		{
			s += y;
			num++;
		}
	}
	
	for (int i = 0 ;i < num/2;i++)
	{
			
		if (s[i] != s[num-i-1])
		{
			ans++;
		}
	} 
	
	cout << ans;
	return 0;
}
