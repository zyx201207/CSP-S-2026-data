#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s1;
	int n,n1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>n1>>s1;
		string s1f=s1+s1;
		string s2=s1;
		while(s2.size()*2<=n1){
			s2+=s2;
		}
		while(s2.size()+s1f.size()<=n1){
			s2+=s1f;
			s1f+=s1;
		}
		while(n1-s2.size()){
			s2+=s1;
		}
		s+=s2;
	}
	long long l=0,r=s.size()-1;
	long long zs=0;
	while(l<=r){
		if(s[l]!=s[r]){
			zs++;
		}
		l++;
		r--;
	}
	cout<<zs;
	return 0;
} 
