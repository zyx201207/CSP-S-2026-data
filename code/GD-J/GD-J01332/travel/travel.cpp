#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int m,n,o,p;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	m=10*a[0]+a[1],n=10*b[0]+b[1],o=10*c[0]+c[1],p=10*d[0]+d[1];
	e=b[2],f=d[2];
	if(m==o){
		cout<<1;
		if(n==p){
			if(e=='A'&&f=='B') cout<<111;
			else if(e=='A'&&f=='C') cout<<110;
			else if(e=='B'&&f=='A') cout<<111;
			else if(e=='B'&&f=='C') cout<<111;
			else if(e=='C'&&f=='A') cout<<110;
			else if(e=='C'&&f=='B') cout<<111;
			else if(e=='D'&&f=='E') cout<<111;
			else if(e=='E'&&f=='D') cout<<111;
			else cout<<100;
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
