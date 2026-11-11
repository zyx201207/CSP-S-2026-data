#include<bits/stdc++.h>
using namespace std;
struct Ticket{
	string train,seat;
	inline friend istream &operator>>(istream &in,Ticket &tick){
		in>>tick.train>>tick.seat;
		return in;
	}
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Ticket A,B;
	cin>>A>>B;
	if(A.train!=B.train){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(A.seat[0]^B.seat[0]||A.seat[1]^B.seat[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((A.seat[2]<='C'&&B.seat[2]>='D')||(A.seat[2]>='D'&&B.seat[2]<='C')){
		cout<<"00";
		return 0;
	} 
	cout<<"1";
	if(abs(A.seat[2]-B.seat[2])!=1){
		cout<<"0";
	}else{
		cout<<"1";
	}
	return 0;
}

