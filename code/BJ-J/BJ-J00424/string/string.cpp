#include<bits/stdc++.h>
using namespace std;
int n,cnt1,cnt2,x;
string s,s1;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>x;
	for(int i=0;i<x;i++){
		int t;
		char c;
		cin>>t>>c;
		while(t--) s+=c;
	}
	s1=s;
	for(int i=0;i<(s1.length()+3)/2-1;i++){
		if(s1[i]!=s1[s1.length()-1-i]){
			s1[s1.length()-1-i]=s1[i];
			cnt1++;
		}
	}
	for(int i=0;i<(s.length()+3)/2-1;i++){
		if(s[i]!=s[s.length()-1-i]){
			s[i]=s[s.length()-1-i];
			cnt2++;
		}
	}
	cout<<min(cnt1,cnt2);
	return 0;
}
