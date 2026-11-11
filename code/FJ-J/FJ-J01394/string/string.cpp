#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	for(int i=0;i<(s.size()-1)/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
