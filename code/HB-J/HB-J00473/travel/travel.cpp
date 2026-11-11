#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a==c)	cout << '1';
	else    cout << '0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1])	cout << '1';
	else    cout << '0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')))	cout << '1';
	else	cout << '0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C'))&&(char(b[2]-1)==d[2]||char(b[2]+1)==d[2]||((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))))	cout << '1';
	else    cout << '0';
	return 0;
}
