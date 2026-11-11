#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int n[a];
	for(int i=0;i<a;i++){
		cin>>i;
	}
	for(int i=1;i<=b;i++){
		int e;
		if((n[i+2]-n[i-1])+(n[i+2]-n[i-1])>b){
			return 0;
		}
		if((n[i+2]-n[i-1])+(n[i+2]-n[i-1])<=b){
			e=3;
	}
	cout<<e;
}}











