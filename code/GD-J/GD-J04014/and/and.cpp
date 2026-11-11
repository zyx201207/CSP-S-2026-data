#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int b;
	int a=[n][0];
	for (int i = 0; i<n; i++){
		cin>>a[i];
	}
	for (int i = 1; i<m; i++){
		b=a[i-1]*a[i];
	}
	cout << b;
	return 0;
}
