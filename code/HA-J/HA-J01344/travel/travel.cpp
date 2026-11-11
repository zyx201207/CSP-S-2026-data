#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y;
	char A[5],B[5],ans[5];
	cin>>x>>A[0]>>A[1]>>A[2]>>y>>B[0]>>B[1]>>B[2];
	if(x==y){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(A[0]==B[0] && A[1]==B[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(A[2]=='D' || A[2]=='F'){
		if(B[2]=='D' || B[2]=='F'){
			cout<<"1";
		}
	}else if(A[2]=='A' || A[2]=='B' || A[2]=='C'){
		if(B[2]=='A' || B[2]=='B' || B[2]=='C'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"00";
		return 0;
	}
	if((A[2]=='A' && B[2]=='B') || (A[2]=='B' && B[2]=='A')){
		cout<<"1";
	}else if((A[2]=='B' && B[2]=='C') || (A[2]=='C' && B[2]=='B')){
		cout<<"1";
	}else if((A[2]=='D' && B[2]=='F') || (A[2]=='F' && B[2]=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
