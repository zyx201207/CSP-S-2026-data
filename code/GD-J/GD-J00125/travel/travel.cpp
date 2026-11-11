#include<bits/stdc++.h> 
using namespace std;
string a;
string b;
string c;
string d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b;
	cin>>c>>d;
	if (a!=c){
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	else{
		cout<<1;}
		//
		if(b[0]==d[0] && b[1]==d[1]) {
			cout<<1;
		}else{
			cout<<0<<0<<0;
		return 0;}
		//
		int ab=99;
		int cd=99;
		if(b[2]=='F'||b[2]=='D'){
			ab=0;
		}if(d[2]=='F'||d[2]=='D'){
			cd=0;
		}
	//	cout<<ab<<' '<<cd<<' ';
		if(ab!=cd){
			cout<<0<<0;
			return 0;
		}else{
			cout<<1;
		}
	
	//
	if((b[2]-d[2])==1 || (b[2]-d[2])==-1 ){
		cout <<1;
		
	}else{
		cout<<0;
	}

	return 0;
}
