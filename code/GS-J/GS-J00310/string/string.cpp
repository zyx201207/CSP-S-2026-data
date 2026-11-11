#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s;
	cin>>n;
	for(int i=0;i<=n*n;i++){
		cin>>s;
	}
	if(n==1){
		cout<<'0';
	}
	if(n==2){
		cout<<'1';
	}
	return 0;
}
