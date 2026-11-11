#include <bits/stdc++.h>
using namespace std;
bool cmp(string s){
	string s1;
	for(long long i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s==s1){
		return true;
	}
	return false;
}
string add(string s){
	for(long long i=0;i<=s.size()-1;i++){
		if(s[i]!=s[s.size()-1-i]){
			s[s.size()-1-i]=s[i];
			return s;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0,n,x;
	string s;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		for(long long j=1;j<=x;j++){
			s+=c;
		}
	}
	while(cmp(s)!=1){
		cnt++;
		s=add(s);
	}
	cout<<cnt;
	return 0;
}

