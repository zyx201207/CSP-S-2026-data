#include<bits/stdc++.h>
using namespace std;
int n;
vector <char> arr;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	int x;
	char y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		for(int j=0;j<x;j++){
			arr.push_back(y);
		}
	}
	for(int i=0;i<=arr.size()/2;i++){
		if(arr[arr.size()/2-i]!=arr[arr.size()/2+i]){
			
		}
	}
	cout<<0; 
	return 0;
} 
