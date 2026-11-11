#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,xc,xs;
	cin >> rc >> rs >> xc >> xs;
	if(rc == xc)
	{
		cout << 1;
		ll ax = 0,bx = 0;
		for(int i = 0;i < 2;i ++)ax = ax * 10 + rs[i] - '0';
		for(int i = 0;i < 2;i ++)bx = bx * 10 + xs[i] - '0';
		if(ax == bx) cout << 1;
		else cout << 0;
		ll ay = rs[2] - 'A' + 1,by = xs[2] - 'A' + 1;
		if(ax==bx && (ay<=3 && by<=3 ||ay>3 && by>3))cout << 1;
		else cout << 0;
		if(abs(ax - bx) <= 1 && (ay<=3 && by<=3 ||ay>3 && by>3)
		 && abs(ay - by) <= 1)cout << 1;
		 else cout << 0;
	}
	else cout << "0000";
	return 0;
} 
