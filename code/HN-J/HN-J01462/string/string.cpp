#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,ans=0;
	string sc;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char s;
		cin>>x>>s;
		for(long long j=0;j<x;j++){
			sc[cnt]=s;
			cnt++;
		}
	}
	for(long long i=0;i<=(cnt-1)/2;i++){
		if(sc[i]!=sc[cnt-i-1]){
			ans++;
		}
	}	 
	cout<<ans;
	return 0;
} 
