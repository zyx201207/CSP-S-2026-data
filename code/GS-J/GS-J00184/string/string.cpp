#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n]={};
	char c[n]={};
	int asum=0;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	int r=0;
	for(int i=1;i<=n;i++){
		if(s[i]!=s[n+1-i]) r++;
	}
	cout<<r;
	
	return 0;
}
