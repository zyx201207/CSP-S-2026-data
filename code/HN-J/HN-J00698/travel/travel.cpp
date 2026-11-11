#include<bits/stdc++.h>
using namespace std;
string ra,rb,xa,xb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ra>>rb>>xa>>xb;
	if(ra==xa){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(rb[0]==xb[0]&&rb[1]==xb[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(rb[2]<='C'){
		if(xb[2]<='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(xb[2]>='D'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(rb[2]=='A'){
		if(xb[2]=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(rb[2]=='B'){
		cout<<1;
	}else if(rb[2]=='C'){
		if(xb[2]=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(rb[2]=='D'){
		if(xb[2]=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		if(xb[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
