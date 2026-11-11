#include <bits/stdc++.h>
using namespace std;
int n,a,sum=0;
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n;i++)
	{
		cin >> a;
		char o;
		cin >>o;
		for(int p = 1;p<=a;p++)
		{
			c+=o;
		}
	}
	for(int i = 0;i<c.length()/2;i++)
	{
		if(c[i]!=c[c.length()-i-1])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}

