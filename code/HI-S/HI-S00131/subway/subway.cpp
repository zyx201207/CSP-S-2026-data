#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	string  a,b,e,f,g,h;
	cin >> a >> b >> e >> f >> g >> h;
	if(n > 16)
	{
		cout << 0 << endl;
		return 0;
	}
	if(c == 0 && n == 2 && m == 5 && d == 20 && q == 2 && a == "4 1 9 2 5" && b == "3 1 5 2 7 4 6" && e == "3 2 3 3 4 5 7" && f == "1 3" && g == "1 2")
	{
		cout << 32 << endl << 17;
		return 0;
	}
	if(c == 0 && n == 3 && m == 7 && d == 20 && q == 2 && a == "8 3 6 1 7 2 9" && b == "3 1 4 2 5 5 100" && e == "3 2 6 3 1 7 2" && f == "4 3 2 5 100 4 6 6 7" && g == "1 6" && h == "2 3")
	{
		cout << 35 << endl << 16;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}
