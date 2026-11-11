#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(long long j=1;j<=x;j++){
			s+=y;
		}
	}
	for(long long i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	for(long long i=0;i<=s.size()-1;i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
