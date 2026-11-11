#include<bits/stdc++.h>
using namespace std;

int x,y;
string a,b;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x >> a >> y >> b;
	if(x!=y){
		printf("0000\n");
		return 0;
	}int n=(a[0]-'0')*10+(a[1]-'0');
	int m=(b[0]-'0')*10+(b[1]-'0');
	if(m!=n){
		printf("1000\n");
		return 0;
	}if((a[2]<='C'&&b[2]>'C')||(a[2]>'C'&&b[2]<='C')){
		printf("1100\n");
		return 0;
	}if((a[2]=='A'&&b[2]!='B')||
		(a[2]=='B'&&b[2]!='A'&&b[2]!='C')||
		(a[2]=='C'&&b[2]!='B')||
		(a[2]=='D'&&b[2]!='F')||
		(a[2]=='F'&&b[2]!='D')){
		printf("1110\n");
		return 0;
	}printf("1111\n");
	return 0;
}