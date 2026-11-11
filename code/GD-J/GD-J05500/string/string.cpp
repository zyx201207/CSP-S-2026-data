#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(string.in);
	freopen(string.out);
	int n;
	cin>>n;
	string s="";
	int m=0;
	for(int i=0;i<n;i++){
		int a;
		string b;
		cin>>a>>b;
		m+=a;
		for(int i=0;i<a;i++)s+=b;
	}
	int cnt=0;
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
}
