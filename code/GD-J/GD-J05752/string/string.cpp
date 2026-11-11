#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
	char a;
	string s;
int main(){
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m;
		cin>>a;
		
		for(long long j=1;j<=m;j++){
		
			s=s+a;
		}
	}
	
	
	
	string s1;
	for(long long i=s.size()-1;i>=0;i--){
		s1=s+s[i];
	}
	if(s==s1){
	
		cout<<0;
		return 0;
	}
	string s3,s4;
	if(s.size()%2==0){
		
		for(long long i=s.size()/2-1;i>=0;i--){
			s3=s3+s[i];
		}
		for(long long i=s.size()/2;i<=s.size()-1;i++){
			s4=s4+s[i];
		}
		for(long long i=0;i<=s.size()/2-1;i++){
			if(s3[i]!=s4[i]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(s.size()%2==1){
		
		for(long long i=s.size()/2-1;i>=0;i--){
			s3=s3+s[i];
		} 
		for(long long i=s.size()/2+1;i<=s.size()-1;i++){
			s4=s4+s[i];
		}
	
		
		for(long long i=0;i<=s.size()/2-1;i++){
			if(s3[i]!=s4[i]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
}
