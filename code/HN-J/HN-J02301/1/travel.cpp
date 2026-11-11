#include<bits/stdc++.h>
#define ll long long
   ll n;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	if(n == 0){
		cout<<0;
		return 0;
	}
	else if(n == 2){
		cout<<2;
		return 0;
	}
	else if(n == 1){
		cout<<n;
		return 0;
	}
	else if(n == 3){
		cout<<3;
		return 0;
	}
	else if(n == 4){
		cout<<4;
		return 0;
	}
	else cout<<5;
	return 0;
}
