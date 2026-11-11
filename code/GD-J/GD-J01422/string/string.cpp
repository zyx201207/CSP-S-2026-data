#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s="";
	long long n;
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--) s+=c;
	}
	long long ans=0;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
