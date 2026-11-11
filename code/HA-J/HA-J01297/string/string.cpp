#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		for(int i=1;i<=n;i++){
			s+=c;
		}
	}
	string ss;
	long long cnt=0,l=s.size();
	for(int i=0;i<s.size();i++){
		ss+=s[l-i-1];
	}
	for(int i=0;i<s.size();i++){
		if(ss[i]!=s[i]){
			cnt++;
			ss[i]=s[i];
			s[l-i-1]=s[i];
		}
	}
	cout<<cnt;
	return 0;
}
