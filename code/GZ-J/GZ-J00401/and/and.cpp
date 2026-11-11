//GZ-J00401 ³ÌÐÞÆë 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n);
	for(auto &x:a)cin>>x;
	sort(a.rbegin(),a.rend());
	if(m==1){
		cout<<a[0];
		return 0;
	}
	if(m==2){
		ll ans=0;
		for(ll i=0;i<n;i++)for(ll j=i+1;j<n;j++)ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	cout<<a[m-1];
}
