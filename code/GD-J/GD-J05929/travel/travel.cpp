#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ac,as,bc,bs;
	cin>>ac>>as>>bc>>bs;
	int a=(ac[0]-'0')*10+ac[1]-'0';
	int b=(bc[0]-'0')*10+bc[1]-'0';
	int c=(as[0]-'0')*10+as[1]-'0';
	int d=(bs[0]-'0')*10+bs[1]-'0';
	bool f1=(as[2]>='A'&&as[2]<='C'&&bs[2]>='A'&&bs[2]<='C'),f2;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0";
	}if(c==d){
		cout<<"1";
	}else{
		cout<<"0";
	}if(f1||f2){
		cout<<"1";
	}else{
		cout<<"0";
	}if(as[2]+1==bs[2]||bs[2]+1==as[2]){
	cout<<"1";
	}else if(as[2]+2==bs[2]||bs[2]+2==as[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
