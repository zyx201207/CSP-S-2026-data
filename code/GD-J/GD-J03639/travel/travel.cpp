#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1]){
    	cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
    	cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char x;
	char y;
	x=b[2];
	y=d[2];
	if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
		cout<<"1";
	}else{
		if(x>='D'&&x<='E'&&y>='D'&&y<='E'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(x==y+1||y==x+1){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
