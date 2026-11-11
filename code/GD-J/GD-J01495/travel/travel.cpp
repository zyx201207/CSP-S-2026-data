#include<bits/stdc++.h>
using namespace std;

int a,b,c,d;
bool f1,f2,f3,f4;
char x,y;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a,&b,&x,&c,&d,&y);
	f1 = (a == c);
	f2 = (b == d);
	f3 = ((x<='C') == (y<='C'));
	f4 = false;
	if((x == 'D' )||( y == 'D')) f4 = ((y=='F')||(x=='F'));
	else f4=(abs(x-y)==1);
	if(f1)cout<<1;
	else cout<<0;
	if(f2 && f1)cout<<1;
	else cout<<0;
	if(f3 && f2 && f1)cout<<1;
	else cout<<0;
	if(f4 && f3 && f2 &&f1)cout<<1;
	else cout<<0;
	return 0;
}

