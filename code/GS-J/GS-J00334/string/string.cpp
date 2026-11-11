#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r"stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	int len=s.size(),cnt;
	for(int i=0;i<=len/2;i++){
		if(s[i]==s[len-1-i]) continue;
		cnt++;
	}
	cout<<cnt;
	return 0;
}
