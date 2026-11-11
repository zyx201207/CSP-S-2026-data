#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int a1,a2,b1,b2;
	char a3,b3;
	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;
	int c1,c2,c3,c4;
	c1=c2=c3=c4=0;
	if(a1 == b1) c1=1;
	if(a2 == b2) c2 = c1;
	if((a3<='C'&&b3<='C')||(a3>='D'&&b3>='D')) c3 = c2;
	if((a3=='D' && b3=='F')||(a3 == b3-1||a3 == b3+1)) c4 = c3;
	cout << c1 << c2 << c3 << c4;
	return 0;
}
