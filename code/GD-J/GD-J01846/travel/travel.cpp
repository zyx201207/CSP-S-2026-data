#include <bits/stdc++.h>
using namespace std;

bool e, f, g, h;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int pai1 = b[0] + b[1], pai2 = d[0] + d[1];
	char wei1 = b[2], wei2 = d[2];
	
	if(a == c)e = 1;
	if(e && pai1 == pai2)f = 1;
	if(f && ((wei1 <= 'C' && wei2 <= 'C') || (wei1 > 'C' && wei2 > 'C')))g = 1;
	
	if(wei1 > wei2)swap(wei1, wei2);
	if(g && ((wei2 == wei1 + 1) || (wei1 == 'D' && wei2 == 'F')))h = 1;
	cout << e << f << g << h;
	return 0;
}
