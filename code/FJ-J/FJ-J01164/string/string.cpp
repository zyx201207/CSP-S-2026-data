#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		char ch;
		cin>>ch;
		for(int i=1;i<=t;i++){
			s+=ch;
		}
	}
	unsigned long long size=s.size()-1;
	int cnt=0;
	for(unsigned long long i=0;i<(size/2);i++){
		if(s[i]!=s[size-i])cnt++;
	}cout<<cnt;
	return 0;
}
