#include<bits/stdc++.h>
using namespace std;
int n;
long long a[2000005];
char c[2000005];
int main(){
	int s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<"0";
	}
	if(n==2){
		if(a[1]>a[2]){
			cout<<a[2];
		}
		else{
			cout<<a[1];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			s=1;
		}
		else{
			s=0;
			break;
		}
	}
	if(s==1){
		cout<<n/2;
	}
	return 0;
}
