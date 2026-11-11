#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[6];
	string c;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		cin >> c;
	}
	if(n == 1)
	{
		for(int i=1;i<=a[1];i++)
		{
			cout << c;
		}
	}
	else if(n == 2)
	{
		if(a[1] >= a[2])
		{
			cout << a[2];
		}
		else
		{
			cout << a[1];
		}
	}
	else
	{
		cout  << n-1;
	}
	return 0;
 } 
