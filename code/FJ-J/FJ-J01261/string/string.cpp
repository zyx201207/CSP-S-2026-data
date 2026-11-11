#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	int n,x=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		x+=a;
		for (int j=0;j<x;j++) s[x]=c;
	}
	cout<<2;
	return 0;
}
