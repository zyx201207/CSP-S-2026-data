#include<bits/stdc++.h>
using namespace std;
string a,b,c,d; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'){
		if(d[2]=='B'){
			cout<<"11";
		}else if(d[2]=='C'){
			cout<<"10";
		}
		else{
			cout<<"00";
		}
	}
	else if(b[2]=='B'){
		if(d[2]=='A'||d[2]=='C'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else if(b[2]=='C'){
		if(d[2]=='B'){
			cout<<"11";
		}else if(d[2]=='A'){
			cout<<"10";
		}
		else{
			cout<<"00";
		}
	}else if(b[2]=='D'){
		if(d[2]=='F'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else if(b[2]=='F'){
		if(d[2]=='D'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	} 	

	return 0;
} 
