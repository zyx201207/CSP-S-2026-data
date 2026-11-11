#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a;
	getchar();
	cin>>b;
	getchar();
	cin>>c;
	getchar();
	cin>>d;
	char b1=b[2],d1=d[2];
	if(a!=c){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	int b2=(b[0]-'0')*10+(b[1]-'0');
	int d2=(d[0]-'0')*10+(d[1]-'0');
	if(b2!=d2){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	if((b1<='C'&&d1>'C')||(b1>'C'&&d1<='C')){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}
	if(abs(b1-d1)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
