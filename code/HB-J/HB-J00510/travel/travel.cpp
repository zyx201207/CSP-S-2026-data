#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a==c) printf("1");
	else{
		printf("0000");
		return 0;
	}for (int i=0;i<2;i++){
		x=x*10+(d[i]-'0');
		y=y*10+(b[i]-'0');
	}if (x==y) printf("1");
	else{
		printf("000");
		return 0;
	}
	if (((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))||((d[2]=='D'||d[2]=='F')&&(b[2]=='D'||b[2]=='F'))) printf("1");
	else{
		printf("00");
		return 0;
	}if (d[2]=='D'||d[2]=='F'||(d[2]>='A'&&d[2]<='C'&&abs(d[2]-b[2])<=1)) printf("1");
	else printf("0");
	return 0;
}
