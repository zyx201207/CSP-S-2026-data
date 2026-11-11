#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int t;char c;
		cin>>t>>c;
		s.append(t,c);
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
