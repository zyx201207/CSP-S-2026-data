#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0;cin>>n;
	char b;string s="";
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	int le=s.size(),mid=s.size()/2;
	for(int i=0;i<mid;i++){
		if(s[i]!=s[le-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
