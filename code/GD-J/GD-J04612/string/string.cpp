#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,x,lenn=0;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		lenn+=x;
		for(int j=1;j<=x;j++) s+=c;
	}
	ll ans=0;
	for(ll i=0;i<lenn/2;i++){
		if(s[i]!=s[lenn-i-1]) ans++; 
	}
	cout<<ans;
	return 0;
}
