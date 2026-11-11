#include<bits/stdc++.h> 
using namespace std;
int c1,c2,p1,p2;
char z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>p1>>z1>>c2>>p2>>z2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2)cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2&&((z1=='A'&&z2=='B')||(z1=='B'&&z2=='A')||(z1=='C'&&z2=='A')||(z1=='A'&&z2=='C')||(z1=='B'&&z2=='C')||(z1=='C'&&z2=='B')||(z1=='D'&&z2=='F')||(z1=='F'&&z2=='D')))cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2&&((z1=='A'&&z2=='B')||(z1=='B'&&z2=='A')||(z1=='B'&&z2=='C')||(z1=='C'&&z2=='B')||(z1=='D'&&z2=='F')||(z1=='F'&&z2=='D')))cout<<1;
	else cout<<0;
}
