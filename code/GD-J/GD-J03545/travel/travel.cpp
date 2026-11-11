#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,q1,q2;
	cin>>s1>>s2>>q1>>q2;
	if(s1==q1)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	string nums,numq;
	char ss1=s2[0],ss2=s2[1],qq1=q2[0],qq2=q2[1];
	nums=ss1+ss2;
	numq=qq1+qq2;
	char seats=s2[2],seatq=q2[2];
	if(nums==numq)cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	if(seats<='C'&&seatq<='C'){
		cout<<"1";
		if(abs(seats-seatq)==1)cout<<"1";
		else cout<<"0";
	}
	else if(seats>='D'&&seatq>='D'){
		cout<<"1";
		if(abs(seats-seatq)==2)cout<<"1";
		else cout<<"0";
	}
	else{
		cout<<"00";
	}
	return 0;
}

