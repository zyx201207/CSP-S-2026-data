#include<bits/stdc++.h>
using namespace std;
int main(){
	int c=0;
	string a;
	int n;
	int j;
	char p;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>j;
		cin>>p;
		for(;j>0;j--){
			a=a+p;
		}
	}
	for(int i=0;i<=a.length()/2;i++){
		if(a[i]!=a[-i+1]){
			c++;
		}
	}
	cout<<c;
	return 0;
}
