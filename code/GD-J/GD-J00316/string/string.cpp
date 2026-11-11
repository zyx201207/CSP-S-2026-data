#include<bits/stdc++.h>
using namespace std;
long long f(string s){
	long long cd=s.size();
	for(long long i=0;i<cd/2+1;i++){
		if(s[i]!=s[cd-i-1]){
			return 0;
		}
	}
	return 1;
}


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	string s;
	string s1;
	long long gs;
	for(int i=1;i<=n;i++){
		cin>>gs>>s1;
		for(int j=1;j<=gs;j++){
			s=s+s1;
		}
	}
	if(f(s)==1) {
		cout<<0;
		return 0;
	}
	int cs=0;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cs++;
		}
	}
	cout<<cs;
	
	
	return 0;
} 
