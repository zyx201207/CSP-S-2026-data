#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[100];
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	string A=a[1];
	string B=a[3];
	string C=a[0];
	string D=a[2];
	if(C[0]*10+C[1]==1||C[0]*10+C[1]==16||C[0]*10+C[1]>17){
		return 0;
	}
	if(D[0]*10+D[1]==1||D[0]*10+D[1]==16||D[0]*10+D[1]>17){
		return 0;
	}
	if(A[0]*10+A[1]>18){
		return 0;
	}
	if(B[0]*10+B[1]>18){
		return 0;
	}
	if(a[0]==a[2]){
		return 0;
	}
	if(A==B){
		return 0;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	if(A[0]==B[0]&&A[1]==B[1]){
		cout<<1;
	} 
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(A[2]=='A'||A[2]=='B'||A[2]=='C'){
		if(B[2]=='A'||B[2]=='B'||B[2]=='C'){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}	
	}
	if(A[2]=='D'||A[2]=='F'){
		if(B[2]=='D'||B[2]=='F'){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}	
	}
	char n=A[2];
	char m=B[2];
	if(n+1==m||n-1==m){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}

 
