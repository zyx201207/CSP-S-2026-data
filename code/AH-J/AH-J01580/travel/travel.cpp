#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
string R_cx,R_seat,X_cx,X_seat;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R_cx>>R_seat>>X_cx>>X_seat;
	if(R_cx == X_cx)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(R_seat[0] == X_seat[0] && R_seat[1] == X_seat[1])cout<<1;
	else cout<<0;
	if(R_seat[2] == 'A'){
		if(X_seat[2] == 'B' || X_seat[2] == 'C')cout<<1;
		else cout<<0;
	}
	else if(R_seat[2] == 'B'){
		if(X_seat[2] == 'A' || X_seat[2] == 'C')cout<<1;
		else cout<<0;
	}
	
	else if(R_seat[2] == 'C'){
		if(X_seat[2] == 'A' || X_seat[2] == 'B')cout<<1;
		else cout<<0;
	} 
	else if(R_seat[2] == 'D'){
		if(X_seat[2] == 'F')cout<<1;
		else cout<<0;
	}
	else if(R_seat[2] == 'F'){
		if(X_seat[2] == 'D')cout<<1;
		else cout<<0;
	}
	
	if(R_seat[2] == 'A'){
		if(X_seat[2] == 'B')cout<<1;
		else cout<<0;
	}
	else if(R_seat[2] == 'B'){
		if(X_seat[2] == 'A' || X_seat[2] == 'C')cout<<1;
		else cout<<0;
	}
	
	else if(R_seat[2] == 'C'){
		if(X_seat[2] == 'B')cout<<1;
		else cout<<0;
	} 
	else if(R_seat[2] == 'D'){
		if(X_seat[2] == 'F')cout<<1;
		else cout<<0;
	}
	else if(R_seat[2] == 'F'){
		if(X_seat[2] == 'D')cout<<1;
		else cout<<0;
	}
	return 0;
}

