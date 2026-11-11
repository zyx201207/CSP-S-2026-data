#include <bits/stdc++.h>
using namespace std;
int n, a[200005], sum, maxx;
char c[200005]; 
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		maxx += a[i];
		for(int j = 1; j <= a[i]; j++) s += c[i];
	}
	for (int i = 0; i <= (maxx - 1) / 2; i++)
	{
		if(s[i] != s[maxx - i - 1])
		{
			sum++;
		}
	}
	cout << sum;
}
//#bits\stdc++.h
//hello ,stranger
//I guess this is my last CSP
//I love OI
//bye
//froepen
//cout >> "6767";
//cin << "6767";
//luogu:A2527
//uid?
//I forget that.
