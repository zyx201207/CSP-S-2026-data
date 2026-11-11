#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<1;
	if(z1[0]!=z2[0]||z1[1]!=z2[1]){
		cout<<0<<0<<0;
		return 0;
	}
	cout<<1;
	if(z1[2]<='C'&&z2[2]>'C'||z1[2]>'C'&&z2[2]<='C'){
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	if(abs(z1[2]-z2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
