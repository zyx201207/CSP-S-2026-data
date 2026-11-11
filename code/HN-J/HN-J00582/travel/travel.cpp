#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	//第一问 
	if(a==c){
		cout <<1;
	}else{
		cout <<"0000";
		return 0;
	}
	//第二问 
	ll b1=(b[0]-'0')*10+(b[1]-'0');
	ll d1=(d[0]-'0')*10+(d[1]-'0');
	if(d1==b1){
		cout <<1;
	}else{
		cout <<"000";
		return 0; 
	}
	//第三问 
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			cout <<1;
		}else{
			cout <<0;
		}
	}else if(b[2]=='D'||b[2]=='F'){
		cout <<1;
	}else{
		cout <<0;
	}
	//第四问 
	if(d[2]=='A'&&b[2]=='B'){
		cout <<1;
	}else if(d[2]=='B'&&(b[2]=='A'||b[2]=='C')){
		cout <<1;
	}else if(d[2]=='C'&&b[2]=='B'){
		cout <<1;
	}else if(d[2]=='D'&&b[2]=='F'){
		cout <<1;
	}else if(d[2]=='F'&&b[2]=='D'){
		cout <<1;
	}else{
		cout <<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//02 01C 02 01D
//1100
