//GZ-J00028 贵阳市白云区华师一学校 白杨梦雪 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	string s="";
	for(ll i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(ll j=1;j<=a;j++){
			s=s+c;
		}
	}
	ll len=s.size();
	ll ans=0;
	for(ll i=0;i<len;i++){
		ll l=n+1-i;
		if(i>l) break;
		if(s[i]!=s[l]) ans++;
	}
	cout<<ans;
	return 0;
}
