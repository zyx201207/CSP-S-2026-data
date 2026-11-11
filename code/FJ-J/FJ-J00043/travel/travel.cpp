#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
int a,c;
string b,d;
cin>>a>>b>>c>>d;	
	if(a==c){
	} 
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]){
		if(b[1]==d[1]){
			cout<<1;
		}
		else{
		cout<<"000";
		return 0;
	}
	}
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'){
		if(d[2]=='B'){
			cout<<11;
			return 0;
		}
		if(d[2]=='C'){
			cout<<10;
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='B'){
		if(d[2]=='A'){
			cout<<11;
			return 0;
		}
		if(d[2]=='C'){
			cout<<11;
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
		if(b[2]=='C'){
		if(d[2]=='B'){
			cout<<11;
			return 0;
		}
		if(d[2]=='A'){
			cout<<10;
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
		if(b[2]=='D'){
		if(d[2]=='F'){
			cout<<11;
			return 0;
		}
	
		else{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='F'){
		if(d[2]=='D'){
			cout<<11;
			return 0;
		}
	
		else{
			cout<<"00";
			return 0;
		}
	}
	
	return 0;
}
