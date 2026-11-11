#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(a[0]==b[0] and a[1]==b[1]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(a[0]==b[0] and a[1]==b[1] and (char)a[2]+(char)b[2]!='C'+'D'){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(abs((char)a[2]-(char)b[2])==1 and (char)a[2]+(char)b[2]!='C'+'D'){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
/*
02 01A 02 01B
*/
