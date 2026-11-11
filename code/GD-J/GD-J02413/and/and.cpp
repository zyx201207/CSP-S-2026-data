#include <bits/stdc++.h> 
using namespace std;
int a, g, d;
int s[200005];
void e(int nub, int kad, int st, int cs)
{
	if(nub >= a || cs == g)
	{
		d = max(d, kad);
		return;
	}
	if(st == 1)
	{
		e(nub + 1, kad, st, cs);
		kad &= s[nub];
		e(nub + 1, kad, st, cs + 1);
	}
	if(st == 0)
	{
		e(nub + 1, kad, st, cs);
		kad = s[nub];
		cs++;
		e(nub + 1, kad, st, cs);
	}
	
}
int main()
{
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin >> a >> g;
	for(int f = 1; f <= a; f++)
	{
		cin >> s[f];
	}
	e(1, 0, 0, 0);
	cout << d;
	return 0;
}
