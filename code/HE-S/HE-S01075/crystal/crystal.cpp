#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int a[1145]={};
	cin>>n>>m;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
		if(a[i]<a[i+1]){
			a[i]=a[i]+1;
			sum = sum + 1;
		}
		}
	}
	cout<<sum-13<<endl; 
	return 0;
}
