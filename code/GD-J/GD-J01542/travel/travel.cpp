#include <bits/stdc++.h>
#define int long long
using namespace std; 

signed main()
{
	// ÓÃscanf,printf!
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin >> a1 >> a2 >> b1 >> b2;
	if (a1 != b1)
	{
		printf("0000");
		return 0;
	}
	if (a2[0] != b2[0] || a2[1] != b2[1])
	{
		printf("1000");
		return 0;
	}
	if (a2[2] < 'D' && b2[2] >= 'D')
	{
		printf("1100");
		return 0;
	}
	if (a2[2] >= 'D' && b2[2] < 'D')
	{
		printf("1100");
		return 0;
	}
	if (a2[2] == 'C' && b2[2] == 'A')
	{
		printf("1110");
		return 0;
	}
	if (a2[2] == 'A' && b2[2] == 'C')
	{
		printf("1110");
		return 0;
	}
	printf("1111");
	return 0;
} 
