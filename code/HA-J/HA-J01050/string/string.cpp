#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ai,sum=0;
	char ci,a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci;
		a=ci;
		if(a==ci){
			sum++;
		}
	}
	if(sum==n){
		cout<<"0";
	}
    
	return 0;
}
