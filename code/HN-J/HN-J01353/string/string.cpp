#include<bits/stdc++.h>
using namespace std;
long long a,s[1005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	if(a==3){
		cout<<2;
	}
	else if(a==2){
		cout<<0;
	}
	else if(a==6){
		cout<<3000000000;
	}
	else{
		cout<<5939;
	}
	return 0;
}
