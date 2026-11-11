#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	char a[n];
	cin>>n>>m;
	cin>>a[n];
	int b(a[n]);
	int c(a[n]-m);
	cout<<max(b,c)<<endl;
	return 0;
} 
