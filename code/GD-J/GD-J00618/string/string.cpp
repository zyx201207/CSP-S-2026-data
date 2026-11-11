#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,max1=0;
	cin>>n;
	string a;
	for(int i=0;i<n;i++){
		int x;
		char y;
		cin>>x>>y;
		sum+=x;
		if(x>=max1) max1=x;
		for(int j=0;j<x;j++){
			a+=y;
		}
	}
	if(sum==1){
		cout<<0;
		return 0;
	}
	string b;
	for(int i=a.size()-1;i>=0;i--){
		b+=a[i];
	}
	if(b==a){
		cout<<0;
		return 0;
	}
	string c;
	if(((sum+1)/2)<=max1){
		cout<<sum-max1;
		return 0;
	}
	if(sum%2==1){
		cout<<(sum-1)/2;
	}else{
		cout<<sum/2;
	}
	return 0;
} 
