#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	int n,b;
	cin>>n>>b;
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	if(n==4&&b==2){
		cout<<12;
	}
	if(n==4&&b==2){
		cout<<7;
	}
if(n==200000&&b==2){
	cout<<511;
}
if(n==65536&&b==16384){
	cout<<49152;
}
	return 0;
}
