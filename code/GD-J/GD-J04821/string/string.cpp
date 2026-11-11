#include<bits/stdc++.h>
using namespace std;
long long n,l,ans=0;
string s,s2;
int hw(string x){
	for(int i=0;i<l;i++){
		s2[i]=s[l-i-1];
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	l=0;
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>s[l];
		for(long long j=1;j<a;j++){
			s[l+j]=s[l];
		}
		l=l+a;
	}
	hw(s);
	if(l%2==1){
		long long x=l/2;
		for(long long i=0;i<x;i++){
			if(s[i]!=s2[i]){
				ans++;
			}
		}
	}else{
		long long x=l/2;
		for(long long i=0;i<x;i++){
			if(s[i]!=s2[i]){
				ans++;
			}
		}
	}
	cout<<ans;
}
