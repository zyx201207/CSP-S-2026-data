#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,p,a=0,s=0,q;
	char c;
	string abc;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p>>c;
		for(int j=0;j<p;j++){
			abc+=c;
			a++;
		}
	}
	a-=1;
	q=a;
	for(int i=0;i<=a;i++){
		if(abc[i]!=abc[q]){
			abc[i]=abc[q];
			s++;
		}
		q--;
	}
	cout<<s;
	return 0;
}
