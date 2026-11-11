#include<bits/stdc++.h>
using namespace std;
int rc,xc,rowr,rowx;
string rs,xs;
bool gd(char a,char b){
	if((a<='C'&&b<='C')||(a>='D'&&b>='D')) return true;
	else return false;
}
bool near(char a,char b){
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')) return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	cin>>rc;
	scanf("%d",&rc);
	cin>>rs;
//	scanf("%s",&rs);
	rowr=(rs[0]-'0')*10+rs[1]-'0';
//	cin>>xc;
	scanf("%d",&xc);
	cin>>xs;
//	scanf("%s",&xs);
	rowx=(xs[0]-'0')*10+xs[1]-'0';
//	cout<<rc<<rs<<xc<<xs;
//	cout<<rowr<<rowx;
	if(rc==xc) printf("%d",1);
	else printf("%d",0);
	if(rc==xc&&rowr==rowx) printf("%d",1);
	else printf("%d",0);
	if(rc==xc&&rowr==rowx&&gd(rs[2],xs[2])==true) printf("%d",1);
	else printf("%d",0);
	if(rc==xc&&rowr==rowx&&gd(rs[2],xs[2])==true&&near(rs[2],xs[2])==true) printf("%d",1);
	else printf("%d",0);
}
/*
02 01C 02 01D
*/
