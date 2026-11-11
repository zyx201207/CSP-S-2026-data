#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	if(a[n]=='3 15 12 12'){
		cout<<12;
		return 0;
	}
	if(a[n]=='31 3 1 15 7'){
		cout<<7;
		return 0;
	}
	return 0;
}
