#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
void solve(){
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(ll j=1;j<=a;j++){
			s+=c;
		}
	}
	
	string t=s;
	reverse(t.begin(),t.end());
	if(s==t){
		cout<<"0";
		return ;
	}
	ll len=s.size();
	ll ans=0;
	for(int ll i=0;i<=(len-1)/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;

}
