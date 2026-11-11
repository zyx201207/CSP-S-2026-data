#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,x,y,s="",t="";
main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x){
		cout<<1;
	}
	else{
		cout<<"0000";
		exit(0);
	}
	s=b[0]+b[1];
	t=y[0]+y[1];
	if(s==t){
		cout<<1;
	}
	else{
		cout<<"000";
		exit(0);
	}
	char l=b[2],r=y[2];
	if((l<='C'&&r<='C')||(l>'C'&&r>'C')){
		cout<<1;
	}
	else{
		cout<<"00";
		exit(0);
	}
	if((l<='C'&&r<='C')){
		if(l=='A'&&r=='B'){
			cout<<1;
		}
		else if(r=='A'&&l=='B'){
			cout<<1; 
		}
		else if(l=='B'&&r=='C'){
			cout<<1;
		}
		else if(r=='B'&&l=='C'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<1;
	}
}
