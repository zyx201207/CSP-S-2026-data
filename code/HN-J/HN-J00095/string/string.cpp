#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0;
	cin>>n;
	string s[n];
	long long m[n];
	for(int i=0;i<n;i++){
		cin>>m[i];
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[i-1]) l++;
	}
	if(l>=n){
		cout<<0;
		return 0;
	}
	cout<<m[0];
}
