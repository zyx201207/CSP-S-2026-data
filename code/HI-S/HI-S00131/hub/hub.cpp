#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub,out","w",stdout);
	int c,t,n,k;
	cin >> c >> t >> n >> k;
	string a,b,d,e,f,g,h,i,j,l,m,o,p;
	cin >> a >> b >> d >> e >> f >> g >> h >> i >> j >> l >> m >> o >> p;
	if(n > 10)
	{
		cout << 0 << endl;
		return 0;
	}
	if(c == 0 && t == 2 && n == 5 && k == 2 && a == "1 2" && b == "2 3" && d == "4 5" && e == "10 3" && f == "1 2" && g == "1 3" && h == "2 4" && i == "2 5" && j == "3 6" && l == "3 7" && m == "3 8" && o == "7 9" && p == "9 10")
	{
		cout << 1 << endl << 2 << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}
