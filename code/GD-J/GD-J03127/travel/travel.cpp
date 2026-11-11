#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int f=0,e=0;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<'0';
		cout<<'0';
		cout<<'0';
		cout<<'0';
		return 0;
	}
	cout<<'1';
	if(b[0]==d[0]&&b[1]==d[1]){
	    cout<<1;
	    e=1;
	}else{
		cout<<0;
	}
	if(e==1&&((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C'))){
	    cout<<1;
	    f=1;
	}else{
		cout<<0;
	}
	if(f==1&&b[2]=='D'&&d[2]=='F'){
		cout<<1;
	}else if(((f==1)&&(b[2]=='A'&&d[2]=='B'))||((f==1)&&(b[2]=='B'&&d[2]=='A'))){
		cout<<1;
	}else if(((f==1)&&(b[2]=='B'&&d[2]=='C'))||((f==1)&&(b[2]=='C'&&d[2]=='B'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
