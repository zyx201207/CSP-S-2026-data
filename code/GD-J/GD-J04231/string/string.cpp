#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>num;
vector<int>word;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int nu,wr;
		cin>>nu>>wr;
		num.push_back(nu);
		word.push_back(wr);
	}
	if(n==1){
		cout<<0;
	}
	else if(n==2){
		if(num[0]!=num[1]){
			if(n%2==0){
				cout<<min(num[0],num[1]);
			} 
			else{
				if(num[0]==1 || num[1]==1){
					cout<<1;
				}
				else cout<<min(num[0],num[1]);
			}
		}
		else cout<<0;
	}
	else {
		int min=num[0];
		for(int i=1;i<n;i++){
			if(min>num[i])min=num[i];
		}
		cout<<min;
	}
	return 0; 
} 
