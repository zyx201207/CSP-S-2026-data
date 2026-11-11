#include<bits/stdc++.h>
using namespace std;

int get(string s)
{
	return 10 * (s[0] - '0') + s[1] - '0';
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int cx,cy,dx,dy;
	char x,y;
	x = b[b.size() - 1],y = d[d.size() - 1];
	cx = get(a),cy = get(b),dx = get(c),dy = get(d);
	cout<<(cx == dx)<<(cx == dx && cy == dy);
	if(cx == dx && cy == dy && ((x <= 'C' && y <= 'C' ) || (x > 'C' && y > 'C')))cout<<1;
	else cout<<0;
	if(x > y)swap(x,y);
	if(y == 'F')y--;
	if(cx == dx && cy == dy && y - x == 1 && y != 'D')cout<<1;
	else cout<<0;
	return 0;
}
