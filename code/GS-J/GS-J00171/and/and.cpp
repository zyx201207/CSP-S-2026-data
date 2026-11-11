#include <bits/stdc++.h>
using namespace std;
const int h = 1e5 + 5;
int a[h],s[h];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout)
	int m;
	int n;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int p = 1,q = 1;
	for (int i = n;i >= 1;i--)
	{
		p *= i;
	}
	for (int i = m;i >= 1;i--)
	{
		q *= i;
	}
	int t = p / q;
	for (int i = 2;i <= t;i++)
	{
		s[i] = a[i + 1];
		for (int j = i;j <= m + i;j++)
		{
			
			s[i] = s[i] && a[j - 1];
		}
		if (i > m)
		{
			break;
		}
	}
	sort(s + 1,s + t + 1);
	cout << s[t];
	return 0;
}
