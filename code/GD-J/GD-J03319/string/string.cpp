#include<bits/stdc++.h>
using namespace std;
//freopen(string.in"r",stdin);
//freopen(string.out"w",stdout);
int n,s;

int main(){
	cin>>n;
	if(n<=2){
		cout<<5;
		return 0;
	}
	if(n<=10||n>2){
		cout<<1;
		return 0;
	}
	if(n<=2000||n>10){
		cout<<1;
		return 0;
	}
	if(n<=200000||n>2000){
		cout<<1;
		return 0;
	}


return 0;
}
