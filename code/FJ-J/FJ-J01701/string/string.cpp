#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,sum=0;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char ch;
		cin>>a>>ch;
		sum+=a;
		for(long long j=1;j<=a;j++) s.push_back(ch);
	}
	for(long long i=0;i<sum/2;i++){
		if(s[0]!=s[n]) ans++;
		n--;
	}
	cout<<ans;
	return 0;
} 
