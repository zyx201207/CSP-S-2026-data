#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	string s;
	long long x=0;
	bool mm=0;
	for(long long i=0;i<n;i++){
		long long k;		
		cin>>k;
		char kk;
		cin>>kk;
		if(k>=1000000000){
			x+=k;
			mm++;
		}
		else for(long long l=0;l<k;l++)s+=kk;
	}
	if(mm){
		cout<<x/2;
		return 0;
	}
	string a;
	for(int i=s.size()-1;i>=0;i--){
		a+=s[i];
	}
	if(a==s){
		cout<<0;
		return 0;	
	}
	if(s.size()%2){
		long long m=0;
		string s1="",s2="";
		for(int i=0;i<s.size()/2;i++){
			s1+=s[i];
		}
		for(int i=s.size()/2+1;i<s.size();i++){
			s2+=s[i];
		}
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i])m++;
		}
		cout<<m;
	}
	else{
		long long m=0;
		string s1="",s2="";
		for(int i=0;i<s.size()/2;i++){
			s1+=s[i];
		}
		for(int i=s.size()/2;i<s.size();i++){
			s2+=s[i];
		}
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i])m++;
		}
		cout<<m;
	}
	return 0;
} 
