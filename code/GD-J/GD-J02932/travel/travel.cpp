#include<bits/stdc++.h>
using namespace std;
int main() {
	string c1,m1,c2,m2;
	cin>>c1>>m1>>c2>>m2;
	if(c1==c2) cout<<1;//条件1 
	else {cout<<"0000";return 0;}
	if(m1[0]==m2[0] && m1[1]==m2[1]) cout<<1;//条件2 
	else {cout<<"000";return 0;}
	if((m1[2]>='A' && m1[2]<='C' && m2[2]>='A' && m2[2]<='C') || (m1[2]>='D' && m1[2]<='F' && m2[2]>='D' && m2[2]<='F')) cout<<1;//条件3 
	else {cout<<"00";return 0;}
	if((m1[2]=='B' || m2[2]=='B') || (m1[2]>='D' && m1[2]<='F' && m2[2]>='D' && m2[2]<='F')) cout<<1;//条件3 
	else {cout<<"0";return 0;}
	return 0;
} 
