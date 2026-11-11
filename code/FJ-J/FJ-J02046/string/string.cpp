#include<iostream>
#include<cmath>
using namespace std;
int n,f;
long long a[100005];
string b[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		cout<<b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i-1]){
			f=1;
		}else{
			break;
		}
	}
	if(n==1 || f==1){
		cout<<0;
	}else if(n==2){
		if(b[1]==b[2]){
			cout<<0;
		}else if(a[1]>=a[2]){
			cout<<a[2];
		}else{
			cout<<a[1];
		}
	}

	return 0;
}
