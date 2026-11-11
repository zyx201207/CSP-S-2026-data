#include<bits/stdc++.h>
using namespace std;
string a,b,c,d; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c) putchar('1');
	else putchar('0');
	if(a==c && b[1]==d[1] && b[0]==d[0]) putchar('1');
	else putchar('0');
	if(a==c && b[1]==d[1] && b[0]==d[0] && ((b[2]<'D' && d[2]<'D') || ((b[2]>='D' && d[2]>='D')))) putchar('1');
	else putchar('0');
	if(a==c && b[1]==d[1] && b[0]==d[0] && ((b[2]<'D' && d[2]<'D') || (b[2]>='D' && d[2]>='D')) && (abs(b[2]-d[2])==1 || (b[2]=='D' && d[2]=='F') || (d[2]=='D' && b[2]=='F'))) putchar('1');
	else putchar('0');
	return 0;
}
