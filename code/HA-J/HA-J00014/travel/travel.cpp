#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y,z,l;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=(a[0]-'0')*10+(a[1]-'0');
	y=(c[0]-'0')*10+(c[1]-'0');
	z=(b[0]-'0')*10+(b[1]-'0');
	l=(d[0]-'0')*10+(d[1]-'0');
	e=max(b[2],d[2]);
	f=min(b[2],d[2]);
	if(x==y){
		cout<<"1";
		if(z==l){
			cout<<"1";
			if((f>='A' && e<='C') || (f=='D' && e=='F')){
				cout<<"1";
				if(e-f==1 || (e-f==2 && e=='F')) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
