#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m;
	char a;
	string s="",s1="";
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>m>>a;
		for(long long j=0;j<m;j++){
			s=s+a;
		}
	}
	long long len=s.length();
	for(long long i=0;i<len;i++){
		s1=s1+s[len-i-1];
	}
	long long ans=0;
    for(long long i=0;i<len;i++){
    	if(s1[i]!=s[i]){
    		ans++;
    		s1[i]=s[i];
    		s[len-i-1]=s1[i];
		}
	}
	cout<<ans;
	return 0;
}
