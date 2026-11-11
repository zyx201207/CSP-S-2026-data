#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r","std.in");
	freopen("string.out","w","std.out");
	int n=0,k=0,s=0;
	cin>>n;
	int a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(b[i-1]!=b[i]){
			k++;
			break;
		}
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	cout<<s/2;
	return 0;
}
