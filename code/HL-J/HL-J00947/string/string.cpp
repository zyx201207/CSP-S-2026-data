#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int x,ans=0;
	char cr;
	string s;
	if(n==1) {
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x>>cr;
		while(x--) s+=cr;
	}
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
}