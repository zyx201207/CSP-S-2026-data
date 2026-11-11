#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,r1;
	string x2,r2;
	cin>>r1>>r2>>x1>>x2;
	if(x1==1||x1==16){
		cout<<"0000";
	}else if(r1==1||r1==16){
		cout<<"0000";
		return 0;
	}
	if(x1==r1){
	cout<<"1";
	}else{
	cout<<"0000";
	return 0;
	}
	if(x2[0]==r2[0]&&x2[1]==r2[1]){
		cout<<"1";
		}else{
		cout<<"000";
		return 0;
		}
		if(x2[2]>='A'&&x2[2]<='C'&&r2[2]>='A'&&r2[2]<='C'||x2[2]>='D'&&x2[2]<='F'&&r2[2]>='D'&&r2[2]<='F'){
		cout<<1;
		}else{
		cout<<0;
		}
		if(r2[2]=='D'&&x2[2]=='C'||x2[2]=='D'&&r2[2]=='C'){
			cout<<0;
			return 0;
		}
		if(x2[2]<'A'||x2[2]>'F'){
			cout<<0;
			return 0;
		}
		if(r2[2]<'A'||r2[2]>'F'){
			cout<<0;
			return 0;
		}
	if((int)x2[2]+1==r2[2]||(int)x2[2]-1==r2[2]){
	cout<<1;
	}else{
	cout<<0;
	}
	
	return 0;
	}
