#include<bits/stdc++.h>
using namespace std;
string A,a,B,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>A>>a>>B>>b;
	int c=0,l=0,w=0;
	if(A[1]==B[1]){
		cout<<"1";
		c=1;
	}else cout<<"0";
	if(a[0]==b[0] && a[1]==b[1] && c){
		cout<<"1";
		l=1;
	}else cout<<"0";
	if(a[2]<='C'&& b[2]<='C' && l){
		cout<<"1";
		w=1;
	}else{
		if(a[2]>='D'&& b[2]>='D' && l){
			cout<<"1";
			w=1;
		}else cout<<"0";
	}
	if(a[0]==b[0] && w){
		if(-1<=a[2]-b[2] && a[2]-b[2]<=1){
			cout<<"1";
		}else cout<<"0";
	}else{
		if(a[1]-b[1]==9){
			cout<<"1";
		}else cout<<"0";
	}
	return 0;
}
