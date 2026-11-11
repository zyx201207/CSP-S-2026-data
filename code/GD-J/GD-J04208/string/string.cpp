#include<iostream>
using namespace std;
int main(){
	int n,cnt=0,a[200000];
	string c;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<=n;i++){
		if(c[i]!=c[i+1]){
			cnt+=a[i];
		}
	}
	return 0;
} 
