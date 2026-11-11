#include<bits/stdc++.h>
using namespace std;
bool ch(char x,char y){
	if(x=='A'||x=='B'||x=='C'&&y=='A'||y=='B'||y=='C'){
		return true;
	}
	if(x=='D'||x=='F'&&y=='D'||y=='F'){
		return true;
	}
	return false;
}
bool h(char d,char c){
	if(d=='A'&&c=='B'){
		return true;
	}
	if(d=='B'&&c=='A'){
		return true;
	}
	if(d=='C'&&c=='B'){
		return true;
	}
	if(d=='B'&&c=='C'){
		return true;
	}
	if(d=='D'&&c=='F'){
		return true;
	}
	if(d=='F'&&c=='D'){
		return true;
	}return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	} 
	else{
		cout<<"0000";
		return 0;
	} 
	 if(b[0]==d[0]&&b[1]==d[1]&&a==c){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&a==c&&ch(b[2],d[2])){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&a==c&&ch(b[2],d[2])&&h(b[2],d[2])){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
