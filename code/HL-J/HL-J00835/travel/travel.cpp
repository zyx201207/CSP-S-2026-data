#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char a,b;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2];
	b=s2[2];
	if(b=='A'||b=='B'||b=='C')	x=1;
	else	x=0;
	if(a=='A'||a=='B'||a=='C')	y=1;
	else	y=0;
	if(c1==c2)	cout<<1;
	else		cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])	cout<<1;
	else	cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&x==y)	cout<<1;
	else	cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((x==0&&y==0)||(x==1&&y==1&&max(a-b,b-a)==1)))	cout<<1;
	else	cout<<0;
	return 0;
}/*
02 01C 02 02C
*/