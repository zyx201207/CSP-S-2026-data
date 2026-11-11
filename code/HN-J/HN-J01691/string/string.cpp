#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n];
	char c[n];
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<"0";
	}
	int q=1;
	for(long long i=0;i<n;i++){
		if(c[i]==c[i+1]){
		    q++;	
		}
	}
	if(q==n){
		cout<<"0";
	}
	return 0;
} 
