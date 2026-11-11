#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,x;
ll n,a;
string rev(string s){
	string r;
	while(s.size()!=0){
		r+=s[ll(s.size()-1)];
		s.erase(s.size()-1,1);
	}
	return r;
}
ll solve(string t,string s){
	ll ans=0;
	for(ll i=0;i<ll(s.size())/2+1;i++)if(s[i]!=t[i])ans++;
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>x;
		while(a--)s+=x;
	}
	string t=rev(s);
	if(t==s)cout<<0;
	else cout<<solve(t,s);
	return 0;
}
