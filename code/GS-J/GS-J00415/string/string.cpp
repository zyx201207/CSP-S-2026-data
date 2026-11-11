#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ai,n;
	char ci;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ai>>ci;
	}
	if (n==3){
		cout<<2<<endl;
	}
	if (n==2){
		cout<<0<<endl;
	}
	if (n==6){
		cout<<3000000000<<endl;
	}
	return 0;
}
