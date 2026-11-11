#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,c;
	char b[5],d[5];
	
	cin>>a>>b>>c>>d;
	
	int bl=(b[0]-'0')*10+b[1]-'0';
	char bn=b[2];
	
	int dl=(d[0]-'0')*10+d[1]-'0';
	char dn=d[2];
	
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	
	if(bl!=dl){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	
	if(bn<='C'&&dn>='D'){
		cout<<"00";
		return 0;
	}
	if(dn<='C'&&bn>='D'){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	
	if(abs(dn-bn)==1){
		cout<<"1";
	}
	else {
		cout<<"0";
	}
	
	return 0;
}
