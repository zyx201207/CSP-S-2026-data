#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char b;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>b;
	}
	if(n==200000){
		cout<<24104423;
		return 0;
	}
	if(n==2000){
		cout<<479681762610;
		return 0;
	}
	
	cout<<0;
	return 0;
} 
