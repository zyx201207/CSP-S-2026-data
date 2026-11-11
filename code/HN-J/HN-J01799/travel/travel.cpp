#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c;
	cin>>b>>d;
	if(a==01||a==16||b==01||b==16){
		cout<<0<<0<<0<<0;
	}
	if(a!=b){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	if(c[0]*10+c[1]==d[0]*10+d[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(c[2]>='A'&&d[2]>='A'&&c[2]<='C'&&d[2]<='C'||c[2]>='D'&&d[2]>='D'&&c[2]<='F'&&d[2]<='F'){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(d[2]-c[2]==1||c[2]-d[2]==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

