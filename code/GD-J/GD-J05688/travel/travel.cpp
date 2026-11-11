#include <bits/stdc++.h>
using namespace std; 
void q4(string m,string n){
	if(m[2]=='B' || n[2]=='B'){
		cout<<1;
	}else{
		cout<<0;
	}
}
void q3(string m,string n){
	if(m[2]=='A' || m[2]=='B'||m[2]=='C'){
		if(n[2]=='A' || n[2]=='B'||n[2]=='C'){
			cout<<1;
			q4(m,n);
		}else{
			cout<<"00";
		}
	}else{
		if(n[2]=='D' || n[2]=='F'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
}
void q2(string m,string n){
	if(m[0]==n[0]&&m[1]==n[1]){
		cout<<1;
		q3(m,n);
	}else{
		cout<<"000";
	}
}
void q1(string a,string b,string m,string n){
	if(a!=b){
		cout<<"0000";
	}
	if(a==b){
		cout<<1;
		q2(m,n);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	struct train{
		string car;
		string seat;
	};
	train r,x;
	cin>>r.car>>r.seat>>x.car>>x.seat;
	q1(r.car,x.car,r.seat,x.seat);
	return 0;
}
