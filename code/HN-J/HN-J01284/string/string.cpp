#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ll x;
	string y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		while(x--){
			s+=y;
		}
	}
	ll l=0,r=s.size()-1;
	for(int i=1;i<=s.size()/2;i++){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
