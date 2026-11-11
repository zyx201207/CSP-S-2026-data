#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e5+5;
ll n,m;
ll o[N];
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++)	cin>>o[i];
	sort(o+1,o+1+n);
	ll ans=o[n],res=-N;
	for(ll i=n;i>=m;i--){
		for(ll j=i;j>=i-m+1;j--)	ans&=o[j];
		if(ans>=res){
			res=ans;
			ans=o[i-1];
		}
		else break;
	}
	cout<<res<<'\n';
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	solve();
	return 0;
}
