#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string e,f;
	e+=b[0];
	e+=b[1];
	f+=d[0];
	f+=d[1];
	if(e==f){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char p=b[2],q=d[2];
	if(p>='A'&&p<='C'&&q>='A'&&q<='C'){
		cout<<1;
		if(p-q==1||p-q==-1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(p>='D'&&p<='F'&&q>='D'&&q<='F'){
		cout<<"11";
	}else{
		cout<<"00";
	}
	return 0;
}
