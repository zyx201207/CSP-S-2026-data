#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL N=2e0;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)	putchar('1');
	else{puts("0000");return 0;}
	if(c2[0]==c4[0]&&c2[1]==c4[1])	putchar('1');
	else{puts("000");return 0;}
	if(c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C')	putchar('1');
	else if(c2[2]>='D'&&c2[2]>='F'&&c4[2]>='D'&&c4[2]<='F')	putchar('1');
	else{puts("00");return 0;}
	if(abs(c2[2]-c4[2])==1)	putchar('1');
	else putchar('0');
	return 0;
}
