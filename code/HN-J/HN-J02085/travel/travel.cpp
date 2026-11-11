#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int w,x,y,z;char c1,c2;
	w=(a[0]-'0')*10+a[1]-'0';
	x=(b[0]-'0')*10+b[1]-'0';c1=b[2];
	y=(c[0]-'0')*10+c[1]-'0';
	z=(d[0]-'0')*10+d[1]-'0';c2=d[2];
	if(w==y){
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(w==y&&x==z){
		cout<<1;
	}
	else {
		cout<<0;
	}//
	if(w==y&&x==z&&((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))){
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(w==y&&x==z&&((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))&&abs(c1-c2)==1){
		cout<<1;
	}
	else {
		cout<<0;
	}
	return 0;
}
