#include <iostream>
using namespace std;
long long a,b,s[200005],n=0,m=0,l;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> a >> b;
	for (int i = 1;i <= a;i++)
	{
		cin >> s[i];
		m = max(s[i],m);
	}
	if (a == b && b != 2)
	{
		l = (s[1] & s[2]);
		for (int i = 2;i <= a-1;i++)
		{
			l = (l & s[i+1]);
		}
		
		cout << l;
		return 0;
	}
	
	if (b == 1)
	{
		cout << m;
		return 0;
	}
	for (int i = 1;i <= a-b+1;i++)
	{
		for (int j = i+1;j <= a;j++)
		{
			n = max(n,(s[i] & s[j]));
			
			
		}
	}
	if (b == 2)
	{
		cout << n;
		return 0;
	}
	cout << m;
} 
