#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string x;
	string X;
	string r;
	string R;
	
	cin>>x>>X>>r>>R;
	
	if(x==r){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(X[0]==R[0]&&X[1]==R[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(X[1]==R[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(X[2]+1==R[2]||X[2]-1==R[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	
	
	
	return 0;
}
