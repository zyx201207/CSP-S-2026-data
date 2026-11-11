#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ll n;
	cin>>n;
	
	ll x;
	string s;
	string ans;
	ll ji=0;
	while(n--){
		cin>>x>>s;
		ji+=x;
		while(x--){
			ans=ans+s;
		}
	}
	ll shu=0;
	for(ll i=0,j=ji-1;i<=j;i++,j--){
		if(ans[i]!=ans[j])shu++;
	}
	cout<<shu;
	return 0;
}
