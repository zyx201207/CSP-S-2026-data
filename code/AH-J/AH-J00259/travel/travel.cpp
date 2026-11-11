#include<bits/stdc++.h>
using namespace std;
string c;
struct lying{
	int cx,n,m;
}r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c;
	r.cx=(c[0]-48)*10+(c[1]-48);
	cin>>c;
	r.n=c[0]*10+c[1];
	r.m=c[2]-'A'+1;
	cin>>c;
	x.cx=(c[0]-48)*10+(c[1]-48);
	cin>>c;
	x.n=c[0]*10+c[1];
	x.m=c[2]-'A'+1;
	if(r.cx!=x.cx)puts("0000");
	else if(r.n!=x.n)puts("1000");
	else if((r.m>0&&r.m<4&&x.m>0&&x.m<4)||(r.m>3&&r.m<6&&x.m>3&&x.m<6)){
		if(abs(r.m-x.m)==1)puts("1111");
		else puts("1110");
	}
	else puts("1100");
}
