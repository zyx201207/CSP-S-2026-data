#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
char b[1000005];
char c[1000005];
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);	
	char s1, s2;
	int c1, c2;
	cin >> c1 >> b[s1] >> c2 >> c[s2];
	if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	else 
	{
		a[1] = 1;
		if(b[2] != c[2])
		{
			
			cout << "1000";
			return 0;
		}
		else
		{
			a[2] = 1;
			
		}
		if(b[3] + 1 == c[3] || b[3] + 2 == c[3] || b[3] - 2 == c[3] || b[3] - 1 == c[3])
		{
			a[3] = 1;
		}
		else
		{
			cout << "1100";
			return 0;
			
		}
		if(b[3] + 1 == c[3] || b[3] - 1 == c[3])
		{
			a[4] = 1;
			cout << a;
		}
		else
		{
			cout << "1110";
			return 0;
			
		}
		
	}
	return 0;	
} 
