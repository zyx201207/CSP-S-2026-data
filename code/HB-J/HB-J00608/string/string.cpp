#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
	}
	else if(n==2){
		cout<<1;
	}
	else{
		cout<<n-1;
	}
return 0;
}
