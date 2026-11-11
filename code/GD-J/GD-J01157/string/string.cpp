#include <bits/stdc++.h>
using namespace std;
string a[200005],b[200005],c;
int n,w,q,y,as = 0,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		s = 0;
		cin >> s >> c;
		for (int j = 1;j <= s;j++)
		{
			a[q+j] = c;
		}
		q += s;
		y += s;
	}
	for (int i = 1;i <= y;i++)
	{
		if (a[q] != a[i])
		{
			a[q] = a[i];
			as++;
		}
		q--;
	}
	cout << as;
	return 0;
} 
