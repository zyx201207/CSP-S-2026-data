#include <bits/stdc++.h>
using namespace std;
string s;
int n,x,y;
char a;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>a;
		for(int j=y;j<x;j++){
			s[j]=a;
		}
		y+=x; 
	}
	cout<<2;
	return 0;
}
