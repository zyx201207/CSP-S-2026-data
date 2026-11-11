#include <bits/stdc++.h>
using namespace std;
int ta,tb,ra,rb;
char ca,cb;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&ta,&ra,&ca,&tb,&rb,&cb);
	bool f1,f2,f3,f4;
	f1=(ta==tb);
	f2=f1&&(ra==rb);
	f3=f2&&((ca<='C' && cb<='C')||(ca>'C' && cb>'C'));
	f4=f3&&(abs(ca-cb)==1);
	cout << f1 << f2 << f3 << f4;
	return 0;
}
