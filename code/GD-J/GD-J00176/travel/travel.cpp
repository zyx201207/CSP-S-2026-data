#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y,xx,yy;
int main(){
	freopen("trvel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=(b[0]-'0')*10+(b[1]-'0'),xx=(d[0]-'0')*10+(d[1]-'0');
	y=b[2]-'A',yy=d[2]-'A';
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&x==xx) cout<<1;
	else cout<<0;
	if(a==c&&x==xx&&((y<=2&&yy<=2)||(y>2&&yy>2))) cout<<1;
	else cout<<0;
	if(a==c&&x==xx&&((y<=2&&yy<=2)||(y>2&&yy>2))&&abs(y-yy)==1) cout<<1;
	else cout<<0;
	return 0;
}
