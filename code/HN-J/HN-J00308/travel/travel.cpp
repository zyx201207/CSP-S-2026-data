#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	char s,s2,x,x2;
	bool a,b,c,d;
	cin>>a1>>a2>>b1>>b2;
	a=(a1==b1);
	b=(((a2[0]+a2[1])==(b2[0]+b2[1])) && a);
	s=a2[2];
	s2=b2[2];
	x=(((s2=='A' || s2=='B') || s2=='C'));
	x2=((s2=='D' || s2=='F'));
	if((s=='A' || s=='B') || s=='C'){
		c=((x && b));
	}
	else{
		c=((x2 && b));
	}
	if(((a2[2]=='A' && b2[2]=='B') && c)){
		d=(1+1==2);
	}
	else if(((a2[2]=='B' && b2[2]=='C') && c) || ((a2[2]=='B' && b2[2]=='A') && c)){
		d=(1+1==2);
	}
	else if(((a2[2]=='C' && b2[2]=='B') && c)){
		d=(1+1==2);
	}
	else if(((a2[2]=='D' && b2[2]=='F') && c)){
		d=(1+1==2);
	}
	else if(((a2[2]=='F' && b2[2]=='D') && c)){
		d=(1+1==2);
	}
	else{
		d=(1+1==3);
	}
	cout<<a<<b<<c<<d;
	return 0;
}
