#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string szx(ll x){
	string s="";
	while(x){
		s += char(x % 2 + '0');
		x /= 2; 
	}
	reverse(s.begin(),s.end());
	return s;
}
string s[200005];
ll t[200005][35],vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,a;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a;
		s[i] = szx(a);
	}
	for(ll i=1;i<=n;i++){
		reverse(s[i].begin(),s[i].end());
		for(ll j=s[i].size();j<=30;j++){
			s[i] += '0';
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<s[i].size();j++){
			if(s[i][j] == '1')t[i][j] ++ ;
		}
	}
	string s1 = "";
	for(ll i=29;i>=0;i--){
		ll cnt = 0;
		for(ll j=1;j<=n;j++){
			if(!vis[j])cnt += t[j][i];
		}
		if(cnt >= m){
			s1 += '1';
			for(ll j=1;j<=n;j++){
				if(!t[j][i])vis[j] = 1;
			}
		}else{
			s1 += '0';
		}
	}
	reverse(s1.begin(),s1.end());
	ll ans = 0,jz = 1;
	for(ll i=0;i<s1.size();i++){
		ll x = s1[i] - '0';
		ans += (x * jz);
		jz *= 2;
	}
	cout<<ans;
	return 0;
}
