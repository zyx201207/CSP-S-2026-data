#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
long long ish(string s){
	string s2="";
	for(long long i=s.size()-1;i>=0;i--){
		s2+=s[i];
	}
	if(s2==s){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	string s;
	long long maxc=0;
	char k;
	for(long long i=1;i<=n;i++){
		long long l;
		scanf("%lld",&l);
		char c;
		cin>>c;
		if(l>maxc){
			k=c;
		}
		for(long long j=0;j<l;j++){
			s+=c;
		}
	}
	if(ish(s)==1){
		printf("%d",0);
		return 0;
	}else{
		long long l=s.size();
		if(l%2==0){
			string s1,s2;
			for(long long i=0;i<l/2-1;i++){
				s1+=s[i];
			}
			for(long long i=l-1;i>=l/2-1;i--){
				s2+=s[i];
			}
			for(long long i=0;i<l/2-1;i++){
				if(s1[i]!=s2[i]){
					cnt++;
				}
			}
		}else{
			string s1,s2;
			for(long long i=0;i<l/2;i++){
				s1+=s[i];
			}
			for(long long i=l-1;i>l/2;i--){
				s2+=s[i];
			}
			for(long long i=0;i<l/2;i++){
				if(s1[i]!=s2[i]){
					cnt++;
				}
			}
		}
	}	
	printf("%lld",cnt);
	return 0;
}
