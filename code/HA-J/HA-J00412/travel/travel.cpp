#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=false;
	if(c1==c2) {
		cout<<'1';
		flag=true;
	}
	else cout<<'0';
	char r=s1[2],x=s2[2];
	int a=0,b=0;
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	if(flag&&a==b){
		cout<<'1';
	}
	else{
		cout<<'0';
		flag=false;
	}
	if(flag&&( (r>='A'&&r<='C'&&x>='A'&&x<='C')||(r>='D'&&r<='F'&&x>='D'&&x<='F') ) ){
		cout<<'1';
	}
	else{
		cout<<'0';
		flag=false;
	}
	if(flag&&abs(x-r)==1) cout<<'1';
	else cout<<'0';
	return 0;
}
