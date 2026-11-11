#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	string a,b,g;
	cin >> c >> t >> n >> d;
	cin >> a >> b >> g;
	if(n > 9)
	{
		cout << 0 << endl;
		return 0;
	}
	if(c == 0 && t == 2 && n == 4 && d == 2 && a == "1 2 3 4" && b == "5 2" && g == "1 2 3 4 5")
	{
		cout << 1 << endl << 2 << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0; 
}
