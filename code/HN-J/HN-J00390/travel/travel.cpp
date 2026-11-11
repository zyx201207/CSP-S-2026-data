#include <bits/stdc++.h>
using namespace std;
int a[10] = {0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,r1,x2,r2;
	cin >> x1 >> x2 >> r1 >> r2;
	if(x1[0] == r1[0])
	{
		a[1] = 1;
	}
	else
	{
		a[1] = 0;
	}
	if(x1[1] == r1[1])
	{
		a[1] = 1;
	}
	else
	{
		a[1] = 0;
	}
	for(int i = 0;i <= 2;i++)
	{
		if(x1[i] == r1[i])
		{
			a[2] = 1;
		}
		else
		{
			a[2] = 0;
		}
	}
	if(a[1] && a[2])
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	
	for(int i = 0;i <= 1;i++)
	{
		if(x2[i] == r2[i])
		{
			a[3] = 1;
		}
		else
		{
			a[3] = 0;
		}
	}
	if(a[3])
	{
		cout << 1;
	}
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	
	if(x2[2] <= 'C' && r2[2] <= 'C')
	{
		a[4] = 1;
	}
	else if((x2[2] <= 'F' && x2[2] >'C') && (r2[2] <= 'F' && r2[2] > 'C'))
	{
		a[4] = 1;
	}
	else
	{
		a[4] = 0;
	}
	if(a[4])
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0;
		return 0;
	}
	
	if(abs(x2[2] + 1 == r2[2] || r2[2] + 1 == x2[2]))
	{
		a[5] = 1;
	}
	else
	{
		a[5] = 0;
	}
	if(a[5])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
