#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int A1,A2;
	string s1,s2;
	cin>>A1>>s1>>A2>>s2;
	if(A1!=A2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]!=s2[0]||s2[1]!=s1[1]){
		cout<<1<<0<<0<<0;
		return 0;
	}
	if(s1[2]<='C'&&s2[2]>'C'){
		cout<<1<<1<<0<<0;
		return 0;
	}
	if(s1[2]>'C'&&s2[2]<='C'){
		cout<<1<<1<<0<<0;
		return 0;
	}
	if(abs(s1[2]-s2[2])!=1){
		cout<<1<<1<<1<<0;
		return 0;
	}
	cout<<1<<1<<1<<1;
	
	return 0;
}
