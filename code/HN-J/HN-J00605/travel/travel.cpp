#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,x,y;
	char n,m;
	int i=0,l=0;
	bool p=false,q=false;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		q=true;
	}
	else cout<<"0";
	x=b[0]+b[1];
	y=d[0]+d[1];
	n=b[2];
	m=d[2];
	i=n;
	l=m;
	if(q){
		if(x==y){
			cout<<"1";
		}
		else cout<<"0";
		if(x==y){
			if(((n>='D')&&(m>='D')) || ((n<='C')&&(m<='C'))){
				cout<<"1";
				p=true;
			}
			else cout<<"0";
		}
		else cout<<"0";
		if(((i==l+1)||(i==l-1)) && p)cout<<"1";
		else cout<<"0";
	}
	else cout<<"000";
	return 0;
}
