#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ai,o=0;
	string ci;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ai>>ci;
		for(int j=0;j<ai;j++){
			b=b+ci;
		}
	}
	long long d=b.size();
	for(int i=0;i<d/2;i++){
		//cout<<b[i]<<' '<<b[d-i-1];
		if(b[i]!=b[d-i-1]){
			o++;}
			
	}
	cout<<o;
	return 0;
}























