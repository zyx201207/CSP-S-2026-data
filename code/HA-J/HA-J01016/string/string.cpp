#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	long long p=0;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(long long j=1;j<=x;j++){
			s[p]=y;
			p++;
		}
	}
	string t;
	for(long long i=0;i<=p;i++){
		t[i]=s[p-i-1];
	}
	long long ans=0;
	for(long long i=0;i<=p;i++){
		if(t[i]!=s[i]){
			cout<<i<<endl;
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
