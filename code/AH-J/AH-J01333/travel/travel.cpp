#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,a1,b1;
	char a2,b2;
	string p,q;
	cin>>a>>p;
	cin>>b>>q;
	a1=(p[0]-'0')*10+p[1]-'0';
	b1=(q[0]-'0')*10+q[1]-'0';
	a2=p[2];
	b2=q[2];
	if(a==b){
		cout<<1;
	}else cout<<0;
	if(a1==b1 && a==b){
		cout<<1;
	}else cout<<0;
	if((a1==b1) && (a==b) && ((a2=='F'&& b2=='D')||(a2=='D'&& b2=='F'))){
		cout<<1;
	}else if((a1==b1) && (a==b) && ((a2=='A'&& b2=='B')||(a2=='A'&&b2=='C')||(a2=='B'&&b2=='A')||(a2=='B'&&b2=='C')||(a2=='C'&&b2=='A')||(a2=='C'&&b2=='B'))){
		cout<<1;
	}else{
		cout<<0;
	}if((a1==b1) && (a==b) && ((a2=='F'&& b2=='D')||(a2=='D'&& b2=='F'))){
		cout<<1;
	}else if((a1==b1) && (a==b) && ((a2=='A'&& b2=='B')||(a2=='B'&&b2=='A')||(a2=='B'&&b2=='C')||(a2=='C'&&b2=='B'))){
		cout<<1;
	}else cout<<0;
	return 0;
}
