#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int c1, s1, c2, s2, a, b, c, d;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 = c2)
		a = 1;
	else
		a = 0;
	if (s1 = s2)
		b = 1;
	else
		b = 0;
	if (c1 = s2)
		c = 1;
	else
		c = 0;
	if (s1 = c2)
		d = 1;
	else
		d = 0;
	cout << a << b << c << d;
	return 0;
}
