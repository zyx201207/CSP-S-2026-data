#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	for(long long k=0;k<n;k++){
		long long num;
		string ls;
		cin>>num>>ls;
		for(long long p=0;p<num;p++){
			s+=ls;
		}
	}
	long long l=s.length();
	long long ans=0;
	if(l%2==0){
		long long t=l/2;
		for(long long i=0;i<t;i++){
			if(s[i]!=s[l-i-1]){
				s[l-i-1]=s[i];
				ans+=1;
			}
		}
	}
	if(l%2!=0){
		long long t=(l-1)/2;
		for(long long i=0;i<t;i++){
			if(s[i]!=s[l-i-1]){
				s[l-i-1]=s[i];
				ans+=1;
		}
	}
}
cout<<ans;
return 0;
}
