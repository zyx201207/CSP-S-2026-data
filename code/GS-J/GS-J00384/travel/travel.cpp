#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e,f;
	cin >> a>> b>> c>> d;
	if(a==c)cout << 1;
	else cout << 0;
	e=b[0]+b[1];
	f=d[0]+d[1];
	if(e==f)cout << 1;
	else cout << 0;
	char g=b[2],h=d[2];
	if(g<='C'&&h<='C')cout << 1;
	else if (g>'C'&&g<='F'&&h>'C'&&h<='F')cout << 1;
	else cout << 0;
	int re=abs(g-h);
	if(re==1)cout << 1;
	else cout << 0;
	return 0;
}
