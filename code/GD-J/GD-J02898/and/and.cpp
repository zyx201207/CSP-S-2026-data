#include<bits/stdc++.h>
using namespace std;
int n, m, s, isa, isb, isno;
int a[1000000];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if(m = n - 1) isno = 1;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		if(a[i] / 2 % 2 != 0) isa = 1;
	}
	
	if(isa == 0)
	{
		sort(a, a + n);
		s = a[n - 1];
		for(int i = n - 2;i >= m;i--)
		{
			if(a[i] < s) s = a[i];
		}
	}
	cout << s;
	return 0;
}
