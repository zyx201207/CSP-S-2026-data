#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;++i){
		long long x;
		string a;
		cin>>x>>a;
		for(int j=1;j<=x;++j){
			s+=a;
		}
	}
	for(int i=0;i<=s.size()/2;++i){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
}
