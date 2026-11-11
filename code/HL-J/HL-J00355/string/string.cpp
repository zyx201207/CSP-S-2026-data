#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	int tm;char ch;
	while(t--){
		cin>>tm>>ch;
		for(int i=1;i<=tm;i++){
			s+=ch;
		}
	}
	int ans=0;
	for(int l=0,r=s.size()-1;l<r;l++,r--){
		if(s[l]!=s[r]){
			ans++;
			
		}
	}
	cout<<ans;
	return 0;
}
