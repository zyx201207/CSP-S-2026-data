#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((c[2]<='C'&&c[2]>='A'&&d[2]<='C'&&d[2]>='A')||(c[2]>'C'&&d[2]>'C')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(c[2]-d[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
