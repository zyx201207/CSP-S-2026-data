#include "bits/stdc++.h"
using namespace std;
int x,y,a,b,c,d;
string sa,sb,sc,sd;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin >> sa >> sb >> sc >> sd;
	x=x*10+(sa[0]-'0'); x=x*10+(sa[1]-'0');
	y=y*10+(sc[0]-'0'); y=y*10+(sc[1]-'0');
	if (x==y) printf ("1");
	else {
		printf ("0000");
		return 0;
	}
	a=a*10+(sb[0]-'0'); a=a*10+(sb[1]-'0');
	b=b*10+(sd[0]-'0'); b=b*10+(sd[1]-'0');
	if (a==b) printf ("1");
	else{
		printf ("000");
		return 0;
	}
	c=sb[2]-'A'+1; d=sd[2]-'A'+1;
	if (c<=3 && d<=3) printf ("1");
	else if (c>=4 && c<=5 && d>=4 && d<=5) printf ("1");
	else{
		printf ("00");
		return 0;
	}
	if (c==1){
		if (d==2) printf ("1");
		else printf ("0");
	}
	else if (c==2){
		if (d==1 || d==3) printf ("1");
		else printf ("0");
	}
	else if (c==3){
		if (d==2) printf ("1");
		else printf ("0");
	}
	else if (c==4){
		if (d==5) printf ("1");
		else printf ("0");
	}
	else if (c==5){
		if (d==4) printf ("1");
		else printf ("0");
	}
	return 0;
}
