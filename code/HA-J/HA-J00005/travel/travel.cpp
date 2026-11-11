#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",std.in);
	freopen("travel.out","w",std.out);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs(b[2]-d[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
}

