#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	for(long long i=0;i<n;i++){
		char s1;
		long long a;
		cin>>a>>s1;
		for(long long j=0;j<a;j++){
			s+=s1;
		}
	}
	
	long long ans;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]){
			ans++;
		}
	}
	if(ans==s.size()/2){
		cout<<0;
	}else{
		long long n=0;
		for(long long i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				n++;
			}
		}
		cout<<n;
	}
	/*string5.in»á±¬ terminate called after throwing an instance of 'std::bad_alloc'
  what():  std::bad_alloc*/
	return 0;
} 
