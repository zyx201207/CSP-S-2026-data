#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char k;
string s; 
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>k;
		for(long long j=1;j<=a;j++)s+=k;
	}
	a=s.size();
	long long b=a;
	a/=2;
	for(long long i=0;i<a;i++){
		if(s[i]!=s[b-i-1]){
			ans+=1;	
		}
	}
	cout<<ans;
	return 0;
} 
