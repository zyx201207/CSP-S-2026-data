#include <bits/stdc++.h>
using namespace std;
int a,b,c,s[300005],p[300005],m=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> a >> b;
	for (int i = 1;i <= a;i++)
	{
		cin >> s[i];
		
	}
	for (int i = 1;i <= b;i++)
	{
		if (s[i] != 0)
		{
			cout << m << " ";
			m++;
		}
	}
	return 0;
	
	
} 
