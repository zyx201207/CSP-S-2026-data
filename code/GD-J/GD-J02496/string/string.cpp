#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	cin>>n;
	string s="";
	char a;
	for(int i=0;i<n;i++){
		cin>>x>>a;
		s+=string(x,a);
	}
	long long cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
