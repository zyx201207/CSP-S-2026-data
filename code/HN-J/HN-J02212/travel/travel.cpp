#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
int f,f1,f2,f3;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		f=1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a==c&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(a==c&&b[1]==d[1]&b[2]<='F'&&b[2]>='D'&&d[2]<='F'&&d[2]>='D'||b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A'){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(a==c&&b[1]==d[1]&b[2]<='F'&&b[2]>='D'&&d[2]<='F'&&d[2]>='D'||b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A'&&int(abs(b[2]-d[2]))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
