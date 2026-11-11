#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		if(x>=5000000){
			cout<<x*2;
			return 0;
		}
		for(int j=1;j<=x;j++){
			s+=c;
		}
		
	}
	string sl,sr;
	for(int i=0;i<s.size()/2;i++){
		sl+=s[i];
	}for(int i=s.size()/2+1;i<s.size();i++){
		sr=s[i]+sr;
	}
	long long o=0;
	for(int i=0;i<s.size()/2;i++){
		if(sl[i]!=sr[i])o++;
	}
	cout<<o;
	
	return 0;
}
