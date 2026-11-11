#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
string s,s1,s2;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		char kl;
		cin>>k>>kl;
		while(k--)
			s+=kl;
	}
	for(int i=s.size()/2-1;i>=0;i--){
		s1+=s[i];
	}
	if(s.size()%2==1)
		for(int i=s.size()-1;i>=s.size()/2+1;i--)
			s2+=s[i];
	else{
		for(int i=s.size()-1;i>=s.size()/2;i--)
			s2+=s[i];
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s2[i]){
			ans1++;
		}
	}
	for(int i=s.size()/2;i<s.size();i++){
		if(s[i]!=s2[i-s.size()/2]){
			ans2++;
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}
