#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0); 
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	unsigned long n;
	cin>>n;
	for(unsigned long long i=0;i<n;i++){
		unsigned long long b;
		char c;
		cin>>b>>c;
		for(unsigned long long j=0;j<b;j++) s+=c;
	}
	string s1;
	bool b=0;
	char c;
	if(s.size()%2!=0){
		b=1;
		c=s[s.size()/2];
	}
	for(unsigned long long i=0;i<s.size()/2;i++) s1+=s[i];
	string s2=string(s1.rbegin(),s1.rend());
	if(b==1) s1+=c;
	s1+=s2;
	unsigned long long cnt=0;
	for(unsigned long long i=0;i<max(s.size(),s1.size());i++){
		if(s[i]!=s1[i]) cnt++;	
	}
	cout<<cnt;
}
