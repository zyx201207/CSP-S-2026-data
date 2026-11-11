#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int main(){
	freopen ("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		std::cin>>a;
		std::cin>>b;
		for(int i=0;i<a;i++){
			s+=b;
		}
	}
	int len=s.size();
	if(len%2==0){
		int cs=0;
		for(int i=0;i<len/2;i++){
			s1+=s[i];
		}
		for(int i=len-1;i>=len/2;i--){
			s2+=s[i];
		}
		for(int i=0;i<len/2;i++){
			if(s1[i]!=s2[i]){
				cs++;
			}
		}
		std::cout<<cs;
	}else{
		int cs=0;
		for(int i=0;i<len/2;i++){
			s1+=s[i];
		}
		for(int i=len-1;i>len/2;i--){
			s2+=s[i];
		}
		for(int i=0;i<len/2;i++){
			if(s[i]!=s2[i]){
				cs++;
			}
		}
		std::cout<<cs;
	}
	return 0;
}
