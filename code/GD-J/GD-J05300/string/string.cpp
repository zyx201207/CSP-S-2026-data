#include<bits/stdc++.h>
using namespace std;
long long n=0,m;
string s;
char c;

void f1(){
	string s1,s2;
	for(long long i=s.size()/2-1;i>=0;i--){
		s1+=s[i];
	}
	int g;
	if(s.size()%2==0){
		for(long long i=s.size()/2-1;i<s.size();i++){
			if(s1[i-s.size()/2+1]!=s[i]){
				m+=1;
				
				s[i]=s1[i-s.size()/2+1];
			}
		}
	}
	else{
		for(long long i=s.size()/2+1;i<s.size();i++){
			if(s1[i-s.size()/2-1]!=s[i]){
				m+=1;
				s[i]=s1[i-s.size()/2-1];
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>m;
		cin>>c;
		for(long long j=0;j<m;j++){
			s+=c;
		}
	}
	m=0;
	f1();
	cout<<m;
	
	

	return 0;
} 
