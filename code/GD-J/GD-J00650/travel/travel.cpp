#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int op1,op2,p1,p2;
	char x,y;
	cin>>op1>>p1>>x>>op2>>p2>>y;
	cout<<(op1==op2)<<((p1==p2)&&(op1==op2));
	bool a=0,b=0;
	if(x=='A'&&y=='B') a=1,b=1;
	else if(x=='B'&&(y=='A'||y=='C')) a=1,b=1;
	else if((x=='A'&&y=='C')||(x=='C'&&y=='A')) a=1,b=0;
	else if((x=='D'&&y=='F')||(x=='F'&&y=='D')) a=1,b=1;
	cout<<(a&&(op1==op2)&&(p1==p2))<<(b&&(op1==op2)&&(p1==p2));
	return 0;
} 
