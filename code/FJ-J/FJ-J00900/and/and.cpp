#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FILE(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
int main(){
	FILE("and")
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n);
	for(ll& i:a)cin>>i;
	for(ll i=30;i>=0;i--){
		vector<ll>b;
		for(ll j=0;j<n;j++)
			if((a[j]>>i)&1)b.push_back(a[j]);
		if(b.size()>=m)a=b;
		n=a.size();
	}ll ans=a[0];
	for(ll i=1;i<m;i++)ans&=a[i];
	cout<<ans;
}
