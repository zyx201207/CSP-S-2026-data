#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
string s,s2;
int main(){;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=0;i<n;i++){
		int a;
		char s1;
		cin>>a>>s1;
		for(int i=0;i<a;i++){
			s+=s1;
		}
	}
	for(int i=s.size()-1;i>0;i--){
		s2+=s[i];
	}
	
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
