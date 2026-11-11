#include<bits/stdc++.h>
using namespace std;
int a[2000005];
char c[2000005];
string s1,s2;
int n,m=1;
int main(){
	freopen("string.in.cpp","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s1+=c[i]*a[i];
	}
	for(int i=n;i>=1;i--){
		s2+=c[i]*a[i];
		if(a[i]!=a[i-1]) m=1;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	else if(s1==s2){
		cout<<0;
		return 0;
	}
	else if(m==1){
		cout<<0;
		return 0;
	}
	else if(n==2){
		if(c[1]==c[2]) cout<<0;
		else{
			if(a[1]>a[2]) cout<<a[2];
			else cout<<a[1]; 
		}
	}	
	
	return 0;
}
