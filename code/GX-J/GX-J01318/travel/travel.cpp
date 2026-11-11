#include<bits/stdc++.h>
using namespace std;
int xa,ra;
string xb,rb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>xa>>xb>>ra>>rb;
	cout <<(xa==ra);
	cout <<((xa==ra)&&(((xb[0]-'0')*10+(xb[1]-'0'))==((rb[0]-'0')*10+(rb[1]-'0'))));
	cout <<((xa==ra)&&(((xb[0]-'0')*10+(xb[1]-'0'))==((rb[0]-'0')*10+(rb[1]-'0')))&&(((xb[2]<='C')&&(rb[2]<='C'))||((xb[2]>='D')&&(rb[2]>='D'))));
	cout <<((xa==ra)&&(((xb[0]-'0')*10+(xb[1]-'0'))==((rb[0]-'0')*10+(rb[1]-'0')))   &&   (((xb[2]>='D')&&(rb[2]>='D'))  ||  ((max(xb[2],rb[2])-min(xb[2],rb[2]))==1)));
	return 0;
}
//priority operator unsigned
//02 01C 02 01A
