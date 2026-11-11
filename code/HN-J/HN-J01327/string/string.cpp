#include<bits/stdc++.h>
using namespace std;
int main(){
int n,r;
cin>>n;
int a[n+5],c[n+5];
int l;
for(int i=1;i<=n;i++){
	cin>>a[i],c[i];
	l+=a[i];
}
int s[l]; 
	for(int i=0;i<=n;i++){
		for(int i=0;i<=a[i];i++){
			s[i]=c[i];
		}
	}
	for(int i=0;i<=l/2;i++){
		if(s[i]==a[l]){
			r++;
		}
	}
	cout<<r;
	return 0;
}
