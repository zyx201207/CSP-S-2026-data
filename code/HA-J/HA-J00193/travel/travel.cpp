#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;string a,b;
	cin >> x >> a >> y >> b;
	char z1 = a[2],z2 = b[2];
	bool c1=0,c2=0,c3=0,c4=0;
	if(x==y) c1=1;
	if(c1&&a[0]==b[0]&&a[1]==b[1]) c2=1;
	if(c2&&((z1<='C'&&z2<='C')||(z1>='D'&&z2>='D'))) c3 = 1;
	if(c3&&abs(z1-z2)==1) c4=1;
	cout << c1<<c2<<c3<<c4;
	return 0;
}
