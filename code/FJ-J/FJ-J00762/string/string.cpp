#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,sum=0;
	cin>>n;
	for(long long i=0;i<n;++i){
		long long t;
		char t1;
		cin>>t>>t1;
		for(long long j=0;j<t;++j){
			s+=t1;
		}
	}
	if(s.size()%2==1){
		char *p1=&s[0];
		char *p2=&s[s.size()-1];
		for(long long i=0;i<=s.size()/2;++i){
			if(*p1!=*p2){
				sum++;
			}
			p1++;
			p2--;
		}
	}
	else{
		char *p1=&s[0];
		char *p2=&s[s.size()-1];
		for(long long i=0;i<s.size()/2;++i){
			if(*p1!=*p2){
				sum++;
			}
			p1++;
			p2--;
		}
	}
	cout<<sum;
	return 0;
}
