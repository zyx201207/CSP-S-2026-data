#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		s+=string(a,c);
	}
	ll ans=0;
	for(int l=0,r=s.size()-1;l<=r;l++,r--) if(s[l]!=s[r]) ans++;
	cout<<ans;
	return 0;
}
