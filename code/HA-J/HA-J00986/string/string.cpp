#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;cin>>n;
	string s;
	for (int i=0;i<n;i++){
		int t;cin>>t;
		string c;cin>>c;
		for (int j=0;j<t;j++){
			s+=c;
		}
	}
	string s1,s2;
	for (long long i=0;i<floor(s.size()/2.0);i++){
		s1+=s[i];
	}
	for (long long i=ceil(s.size()/2.0);i<s.size();i++){
		s2+=s[i];
	}
	for (long long i=0;i<s1.size();i++){
		if (s1[i]!=s2[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
