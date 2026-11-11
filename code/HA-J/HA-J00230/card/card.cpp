#include<bits/stdc++.h>
using namespace std;
int n;
int a[2000000];
char c[2000000],s1,s2;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s1+=c[i];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=a[i];j>=1;j--){
			s2+=c[i];
		}
	}
	if(s1==s2){
		cout<<"0";
	}
	return 0;
}
