#include <iostream>
#include <bits/stdc++.h>
using namespace std;
	int n,num[10000];
	char arr[10000],arr2[10000];

int main(){
	freopen("string.in","r",string.in);
freopen("string.out","w",string.out);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i]>>arr[i];
	}
	int t=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<num[i];j++){
			arr2[t++]=arr[i];
		}
	}
	int l=0,r=n-1,cut=0;
	while(l<=r){
		if(arr2[l]!=arr2[r]){
			cut++;
		}
		l++,r--;
	}
	cout<<cut;
	return 0;
}
